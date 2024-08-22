#include "mainwindow.h"
#include "loginwidget.h"
#include <QApplication>
#include "global.h"
#include "databasemagr.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyApp::InitApp(a.applicationDirPath());
    myHelper::setStyle("default");
    // 加载数据库
    DataBaseMagr::Instance()->OpenUserDb(MyApp::m_strDatabasePath + "user.db");
    DataBaseMagr::Instance()->OpenMessageDb(MyApp::m_strDatabasePath + "msg.db");
    LoginWidget w;
    myHelper::FormInCenter(&w);
    w.show();
    return a.exec();
}
