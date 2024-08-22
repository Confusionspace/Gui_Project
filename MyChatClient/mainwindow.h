  #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QButtonGroup>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QJsonObject>

#include "chatstackedwidget.h"
#include "clientsocket.h"
#include "commonapi/qqcell.h"
#include "databasemagr.h"
#include "customwidget.h"
#include "commonapi/myapp.h"
#include "commonapi/unit.h"
#include "chatwindow.h"
#include "systemsetting.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public CustomMoveWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setSocket(ClientSocket *tcpSocket,const QString &name);

private slots:
    void SltMainPageChanged(int index);
    void SltTrayIcoClicked(QSystemTrayIcon::ActivationReason reason);
    void SltTrayIconMenuClicked(QAction *action);
    void SltQuitApp();

    //群组点击
    void SltGroupsClicked(QQCell *);
    //好友点击
    void SltFriendsClicked(QQCell *);
    // 用户接受处理
    void SltReadMessages(const QJsonValue &json, const int &id);

    // 右键菜单
    void onAddFriendMenuDidSelected(QAction *action);
    void onGroupPopMenuDidSelected(QAction *action);
    void onChildPopMenuDidSelected(QAction *action);

    //TcpSocket关联的槽函数
    void SltTcpReply(const quint8 &type, const QJsonValue &dataVal);
    void SltTcpStatus(const quint8 &state);

    // 消息窗口管理
    void SltFriendChatWindowClose();
    void SltGroupChatWindowClose();

    //菜单栏
    void SltSysmenuCliecked(QAction *action);


private:
    Ui::MainWindow *ui;
    ClientSocket *m_tcpSocket;
    QButtonGroup *m_btngroup;
    QSystemTrayIcon *systemTrayIcon;
    QList<ChatWindow*> m_chatGroupWindows;
    QList<ChatWindow *> m_chatFriendWindows;

    void InitQQListMenu();
    void InitSysTrayIcon();
    void InitSysMenu();
    void PraseAddFriendReply(const QJsonValue &dataVal);
    void PraseAddFriendRequist(const QJsonValue &dataVal);

    // 好友添加请求确认
    void ParseAddFriendRequest(const QJsonValue &dataVal);
    void ParseAddGroupRequest(const QJsonValue &dataVal);

    void ParseGetFriendsReply(const QJsonValue &dataVal);
    void ParseGetGroupFriendsReply(const QJsonValue &dataVal);

    void UpdateFriendStatus(const quint8 &nStatus, const QJsonValue &dataVal);
    void ParseCreateGroupReply(const QJsonValue &dataVal);
    void ParseAddGroupReply(const QJsonValue &dataVal);

    void ParseFriendMessageReply(const QJsonValue &dataVal);

    void AddMyGroups(const QJsonValue &dataVal);

    void ParseUpFriendHead(const QJsonValue &dataVal);

    // 头像图片的获取
    QString GetHeadPixmap(const QString &name) const;
    void DownloadFriendHead(const int &userId, const QString &strHead);

    void ParseGroupMessageReply(const QJsonValue &dataVal);
    // QWidget interface

};


#endif // MAINWINDOW_H
