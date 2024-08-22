#include "clientsocket.h"
#include "databasemagr.h"

#include <QFile>
#include <QDebug>
#include <QHostAddress>
#include <QDataStream>
#include <QApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include "unit.h"
#include "myapp.h"


ClientSocket::ClientSocket(QObject *parent) :
    QObject(parent)
{
    m_nId = -1;

    m_tcpSocket = new QTcpSocket(this);

    connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(SltReadyRead()));
    connect(m_tcpSocket, SIGNAL(connected()), this, SLOT(SltConnected()));
    connect(m_tcpSocket, SIGNAL(disconnected()), this, SLOT(SltDisconnected()));
}

ClientSocket::~ClientSocket()
{
}

/**
 * @brief ClientSocket::GetUserId
 * 获取当前用户id
 * @return
 */
int ClientSocket::GetUserId() const
{
    return  m_nId;
}

void ClientSocket::SltSendOnline()
{
    // 上线的时候给当前好友上报下状态
    QJsonArray friendArr = DataBaseMagr::Instance()->GetMyFriend(MyApp::m_nId);
    // 组织Jsonarror
    SltSendMessage(UserOnLine, friendArr);
}


/**
 * @brief ClientSocket::SendOffline
 */
void ClientSocket::SltSendOffline()
{
    QJsonObject json;
    json.insert("id", m_nId);
    QJsonArray friendArr = DataBaseMagr::Instance()->GetMyFriend(MyApp::m_nId);
    json.insert("friends", friendArr);

    // 通知我的好友，我下线了
    this->SltSendMessage(Logout, json);
}
/**
 * @brief ClientSocket::SetUserId
 * 设置当前socket的用户id
 * @param id
 */
void ClientSocket::SetUserId(const int &id)
{
    m_nId = id;
}

void ClientSocket::CheckConnected()
{
    if (m_tcpSocket->state() == QTcpSocket::UnconnectedState)
    {
        m_tcpSocket->connectToHost(MyApp::m_strHostAddr, MyApp::m_nMsgPort);
        qDebug() << "正在连接服务器";
        m_tcpSocket->waitForConnected(3000);
        if(m_tcpSocket->state() == QTcpSocket::ConnectedState)
            qDebug() << "连接成功";
        else
            qDebug() << "连接失败"<<MyApp::m_strHostAddr<<MyApp::m_nMsgPort;
    }
    else
    {
        qDebug() << "Socket is already connected or in the process of connecting.";
    }
}

/**
 * @brief ClientSocket::CloseConnected
 * 主动断开连接
 */
void ClientSocket::CloseConnected()
{
    if (m_tcpSocket->isOpen()) m_tcpSocket->abort();
}

/**
 * @brief ClientSocket::ConnectToHost
 * 链接服务器接口
 * @param host
 * @param port
 */
void ClientSocket::ConnectToHost(const QString &host, const int &port)
{
    if (m_tcpSocket->isOpen()) m_tcpSocket->abort();
    m_tcpSocket->connectToHost(host, port);
}

/**
 * @brief ClientSocket::ConnectToHost
 * 链接服务器接口
 * @param host
 * @param port
 */
void ClientSocket::ConnectToHost(const QHostAddress &host, const int &port)
{
    if (m_tcpSocket->isOpen()) {
        m_tcpSocket->abort();
    }
    m_tcpSocket->connectToHost(host, port);
}


/**
 * @brief ClientSocket::SltSendMessage
 * tcp socket消息管理
 * @param type
 * @param dataVal
 */
void ClientSocket::SltSendMessage(const quint8 &type, const QJsonValue &dataVal)
{
    // 连接服务器
    if (!m_tcpSocket->isOpen()) {
        m_tcpSocket->connectToHost(MyApp::m_strHostAddr, MyApp::m_nMsgPort);
        m_tcpSocket->waitForConnected(3000);
    }
    // 超时1s后还是连接不上，直接返回
    if (!m_tcpSocket->isOpen()) {
        qDebug() << "Failed to connect to host!";
        return;
    }

    // 构建 Json 对象
    QJsonObject json;
    json.insert("type", type);
    json.insert("from", m_nId);
    json.insert("data", dataVal);

    // 构建 Json 文档
    QJsonDocument document;
    document.setObject(json);
    qDebug() << "m_tcpSocket->write:" << document.toJson(QJsonDocument::Compact);
    if (m_tcpSocket->state() == QTcpSocket::ConnectedState) {
        m_tcpSocket->write(document.toJson(QJsonDocument::Compact));
    } else {
        qDebug() << "Socket is not connected!";
    }
}

/**
 * @brief ClientSocket::SltDisconnected
 */
void ClientSocket::SltDisconnected()
{
    qDebug() << "has disconnecetd";
    m_tcpSocket->abort();
}

/**
 * @brief ClientSocket::SltConnected
 */
void ClientSocket::SltConnected()
{
    qDebug() << "has connecetd";
    emit signalStatus(ConnectedHost);
}

void ClientSocket::ParseReister(const QJsonValue &dataVal)
{
    if(dataVal.isObject())
    {
        QJsonObject dataObj=dataVal.toObject();
        m_nId=dataObj.value("id").toInt();
        if(-1 == m_nId)
            Q_EMIT signalStatus(RegisterOk);
        else
            Q_EMIT signalStatus(RegisterFailed);
    }
}


/**
 * @brief ClientSocket::SltReadyRead
 * 服务器消息处理
 */
void ClientSocket::SltReadyRead()
{
    //读取socket数据
    QByteArray byRead= m_tcpSocket->readAll();
    QJsonParseError jsonError;
    //转换为JSON文档
    QJsonDocument document=QJsonDocument::fromJson(byRead,&jsonError);;
    //解析未发生错误
    if(!document.isNull()&&(jsonError.error==QJsonParseError::NoError))
    {
        //json文档对象
        if(document.isObject())
        {
            //转化为对象
            QJsonObject jsonObj=document.object();
            QJsonValue dataVal=jsonObj.value("data");
            int nType=jsonObj.value("type").toInt();
            int nFrom=jsonObj.value("from").toInt();

            switch (nType) {
            case Register:
            {
                ParseReister(dataVal);
            }
            break;
            case Login:
            {
                ParseLogin(dataVal);
            }
            break;
            case UserOnLine:
            {
                qDebug() << "user is oline" << dataVal;
                Q_EMIT signalMessage(UserOnLine, dataVal);
            }
            break;
            case UserOffLine:
            {
                qDebug() << "user is offline" << dataVal;
                Q_EMIT signalMessage(UserOffLine, dataVal);
            }
            break;
            case Logout:
            {
                m_tcpSocket->abort();
            }
            break;
            case UpdateHeadPic:
            {
                Q_EMIT signalMessage(UpdateHeadPic, dataVal);
            }
            break;
            case AddFriend:
            {
                Q_EMIT signalMessage(AddFriend, dataVal);
            }
            break;
            case AddGroup:
            {
                Q_EMIT signalMessage(AddGroup, dataVal);
            }
            break;
            case AddFriendRequist:
            {
                Q_EMIT signalMessage(AddFriendRequist, dataVal);
            }
            break;
            case AddGroupRequist:
            {
                Q_EMIT signalMessage(AddGroupRequist, dataVal);
            }
            break;
            case CreateGroup:
            {
                Q_EMIT signalMessage(CreateGroup, dataVal);
            }
            break;
            case GetMyFriends:
            {
                Q_EMIT signalMessage(GetMyFriends, dataVal);
            }
            break;
            case GetMyGroups:
            {
                Q_EMIT signalMessage(GetMyGroups, dataVal);
            }
            break;
            case RefreshFriends:
            {
                Q_EMIT signalMessage(RefreshFriends, dataVal);
            }
            break;
            case RefreshGroups:
            {
                Q_EMIT signalMessage(RefreshGroups, dataVal);
            }
            break;
            case SendMsg:
            {
                Q_EMIT signalMessage(SendMsg, dataVal);
            }
            break;
            case SendGroupMsg:
            {
                Q_EMIT signalMessage(SendGroupMsg, dataVal);
            }
            break;
            case SendFile:
            {
                Q_EMIT signalMessage(SendFile, dataVal);
            }
            break;
            case SendPicture:
            {
                Q_EMIT signalMessage(SendPicture, dataVal);
            }
            break;
            default:
                break;
            }
        }
    }
}

//用户登录
void ClientSocket::ParseLogin(const QJsonValue &dataVal)
{
    QJsonObject dataObj=dataVal.toObject();
    int id=dataObj.value("id").toInt();
    int code=dataObj.value("code").toInt();
    QString msg=dataObj.value("msg").toString();
    if(code==-2)
    {
        qDebug()<<"用户已在线";
        m_nId=id;
        emit signalStatus(LoginRepeat);
    }
    else if(code==-1) {
        qDebug()<<"用户未注册";
        emit signalStatus(LoginPasswdError);
    }
    else if(code==0&&msg=="ok")
    {
        m_nId=id;
        MyApp::m_nId=id;
        qDebug()<<"登录成功";
        emit signalStatus(LoginSuccess);
    }
}
