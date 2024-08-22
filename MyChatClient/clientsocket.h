#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QFile>

/////////////////////////////////////////////////////////////////////////
/// \brief The ClientSocket class
/// socket通信类
class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QObject *parent = 0);
    ~ClientSocket();

    // 获取当前用户的ID
    int GetUserId() const;
    void SetUserId(const int &id);

    void CheckConnected();
    void CloseConnected();

    // 连接服务器
    void ConnectToHost(const QString &host, const int &port);
    void ConnectToHost(const QHostAddress &host, const int &port);
signals:
    void signalMessage(const quint8 &type, const QJsonValue &dataVal);
    void signalStatus(const quint8 &state);
public slots:
    // socket消息发送封装
    void SltSendMessage(const quint8 &type, const QJsonValue &dataVal);
    // 发送上线通知
    void SltSendOnline();
    // 发送下线通知
    void SltSendOffline();
private:
    // tcpsocket
    QTcpSocket *m_tcpSocket;
    int m_nId;
private slots:
    // 与服务器断开链接
    void SltDisconnected();
    // 链接上服务器
    void SltConnected();
    // tcp消息处理
    void SltReadyRead();

private:
    // 解析登陆返回信息
    void ParseLogin(const QJsonValue &dataVal);
    // 解析注册返回信息
    void ParseReister(const QJsonValue &dataVal);
};


#endif //TCPCLIENT_H
