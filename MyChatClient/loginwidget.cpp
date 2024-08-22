#include "loginwidget.h"
#include "ui_loginwidget.h"
#include <QFile>
#include "mainwindow.h"
#include "unit.h"
#include "global.h"
LoginWidget::LoginWidget(QWidget *parent)
    : CustomMoveWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    ui->lineEditPasswed->setEchoMode(QLineEdit::Password);
    //去掉Qt自带的标题
    this->setWindowFlags(Qt::FramelessWindowHint);
    //使透明生效
    this->setAttribute(Qt::WA_TranslucentBackground);
    myHelper::setStyle("default");
    m_bConnected = false;
    //给LineEdit添加icon
    ui->lineEditUser->SetIcon(QPixmap(":/resource/common/ic_user.png"));
    ui->lineEditPasswed->SetIcon(QPixmap(":/resource/common/ic_lock.png"));

    m_tcpSocket=new ClientSocket();
    connect(m_tcpSocket,&ClientSocket::signalMessage,this,&LoginWidget::onsignalMessage);
    connect(m_tcpSocket,&ClientSocket::signalStatus,this,&LoginWidget::onsignalStatus);
    m_tcpSocket->CheckConnected();
}

LoginWidget::~LoginWidget()
{
    delete ui;
}

/**
* @brief LoginWidget::on_btnRegedit_clicked
* 用户注册
*/
void LoginWidget::on_btnRegedit_clicked()
{
   // 如果没有链接上服务器，此时进行一次链接
   if (!m_bConnected) {
       m_tcpSocket->ConnectToHost(MyApp::m_strHostAddr, MyApp::m_nMsgPort);
       CMessageBox::Infomation(this, "未连接服务器，请等待！");
       return;
   }

   // 构建 Json 对象
   QJsonObject json;
   json.insert("name", ui->lineEditUser->text());
   json.insert("passwd", ui->lineEditPasswed->text());

   m_tcpSocket->SltSendMessage(Register, json);
}
void LoginWidget::on_btnWinMenu_clicked()
{
    ui->stackedWidget->setStartVal(0);
    ui->stackedWidget->setEndVal(180);
    ui->stackedWidget->animation(1);
}

void LoginWidget::on_btnCancel_clicked()
{
    ui->stackedWidget->setStartVal(0);
    ui->stackedWidget->setEndVal(-180);
    ui->stackedWidget->animation(0);

}


void LoginWidget::on_btnLogin_clicked()
{

    QString username=ui->lineEditUser->text();
    QString passwd=ui->lineEditPasswed->text();

    // 构建 Json 对象
    QJsonObject json;
    json.insert("name", username);
    json.insert("passwd", passwd);
    m_tcpSocket->SltSendMessage(Login,json);

}

void LoginWidget::onsignalMessage(const quint8 &type, const QJsonValue &dataVal)
{

}

void LoginWidget::onsignalStatus(const quint8 &state)
{
    switch (state) {
    case ConnectedHost:
        ui->labelWinTitle->setText("已连接服务器");
        break;
    case LoginSuccess:  //用户登录成功
    {
        disconnect(m_tcpSocket,&ClientSocket::signalStatus,this,&LoginWidget::onsignalStatus);
        disconnect(m_tcpSocket,&ClientSocket::signalMessage,this,&LoginWidget::onsignalMessage);

        qDebug()<<"用户登录成功";
        //登录按钮
        MainWindow *mainWindow=new MainWindow;
        mainWindow->setSocket(m_tcpSocket,ui->lineEditUser->text());
        mainWindow->show();
        //登录窗口隐藏
        this->hide();
    }
        break;
    case LoginPasswdError: //用户未注册
        qDebug()<<"用户未注册";
        break;
    case LoginRepeat: //用户已在线
        qDebug()<<"用户已在线";
        break;
    default:
        break;
    }
}

