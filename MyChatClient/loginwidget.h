#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include "clientsocket.h"
#include "customwidget.h"
#include <QJsonObject>
#include <QJsonDocument>
namespace Ui {
class LoginWidget;
}

class LoginWidget : public CustomMoveWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private slots:
    void on_btnWinMenu_clicked();


    void on_btnCancel_clicked();

    void on_btnLogin_clicked();

    void onsignalMessage(const quint8 &type, const QJsonValue &dataVal);
    void onsignalStatus(const quint8 &state);
    void on_btnRegedit_clicked();

private:
    Ui::LoginWidget *ui;
    bool m_bConnected;
    ClientSocket *m_tcpSocket;

};

#endif // LOGINWIDGET_H
