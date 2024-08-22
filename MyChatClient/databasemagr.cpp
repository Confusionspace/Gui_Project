#include "databasemagr.h"

#include <QDebug>

DataBaseMagr *DataBaseMagr::self = NULL;

DataBaseMagr::DataBaseMagr(QObject *parent) :
    QObject(parent)
{

}

DataBaseMagr::~DataBaseMagr()
{
    if (userdb.isOpen()) {
        userdb.close();
    }
}

/**
 * @brief DataBaseMagr::OpenDb
 * 打开数据库
 */
bool DataBaseMagr::OpenUserDb(const QString &dataName)
{
    userdb = QSqlDatabase::addDatabase("QSQLITE", "connectionUser");
    userdb.setDatabaseName(dataName);
    if (!userdb.open()) {
        qDebug() << "Open sql failed";
        return false;
    }

    // 添加数据表
    QSqlQuery query(userdb);

    // 创建我的好友表 id为好友id，userid为当前用户id
    query.exec("CREATE TABLE FRIEND (id INT, userId INT, name varchar(50))");

    // 创建群组表 id为群组id，userid为当前用户id
    query.exec("CREATE TABLE MYGROUP (id INT, userId INT, name varchar(50))");

    // 用户数据保存
    query.exec("CREATE TABLE USERINFO (id INT, name varchar(50), passwd varchar(50))");

    return true;
}
bool DataBaseMagr::OpenMessageDb(const QString &dataName)
{
    msgdb = QSqlDatabase::addDatabase("QSQLITE", "connectionMsg");
    msgdb.setDatabaseName(dataName);
    if (!msgdb.open()) {
        qDebug() << "Open sql failed";
        return false;
    }

    // 添加数据表
    QSqlQuery query(msgdb);
    // 创建历史聊天表
    query.exec("CREATE TABLE MSGINFO (id INT PRIMARY KEY, userId INT, name varchar(20),"
               "head varchar(50), datetime varchar(20), filesize varchar(30),"
               "content varchar(500), type INT, direction INT)");

    return true;
}

bool DataBaseMagr::isMyFriend(const int &userId, const QString &name)
{
    QString strQuery="select [id] from friend";
    strQuery.append(QString("where name=%1").arg(name));
    strQuery.append(QString(" and userId=%1").arg(QString::number(userId)));

    QSqlQuery query(strQuery,userdb);
    return query.next();
}

QJsonArray DataBaseMagr::GetMyGroup(const int &userId) const
{
    QJsonArray mygroup;
    QString strQuert="select [id] [name] FROM MYGROUP";
    strQuert.append("where userId=");
    strQuert.append(QString::number(userId));

    QSqlQuery query(strQuert,userdb);
    while(query.next())
    {
        QJsonObject jsonObj;
        jsonObj.insert("id",query.value("id").toInt());
        jsonObj.insert("name",query.value("name").toString());
        mygroup.append(jsonObj);
    }
    return mygroup;
}

QJsonArray DataBaseMagr::GetMyFriend(const int &userId)
{
    QJsonArray myfriend;
    QString strQuery="select [id] from friend";
    strQuery.append(QString("where userId=%1").arg(QString::number(userId)));
    QSqlQuery query(strQuery,userdb);
    while(query.next())
    {
        myfriend.append(query.value("id").toInt());
    }

    return myfriend;
}

//创建群组
void DataBaseMagr::AddGroup(const int &id, const int &userId, const QString &name)
{
    QString strQuery="select [id] from MYGROUP";
    strQuery.append("where id=");
    strQuery.append(QString::number(id));
    strQuery.append("and userId=");
    strQuery.append(QString::number(userId));

    QSqlQuery query(strQuery,userdb);
    if(query.next())
    {
        // 查询到有该用户，不添加
        qDebug() << "yes" << query.value(0).toString();
        return;
    }

    query.prepare("insert into MYGROUP(id,userId,name)"
                  "Value(?,?,?)");
    query.bindValue(0,id);
    query.bindValue(1,userId);
    query.bindValue(2,name);
    query.exec();
}

bool DataBaseMagr::isInGroup(const QString &name)
{
    QString strQuery = "SELECT [id] FROM MYGROUP ";
    strQuery.append("WHERE name='");
    strQuery.append(name);
    strQuery.append("';");

    QSqlQuery query(strQuery, userdb);
    return query.next();
}

void DataBaseMagr::AddFriend(const int &friendId, const int &userId, const QString &name)
{
    QString strQuery="select [id] from FRIEND";
    strQuery.append(QString("where id=%1").arg(QString::number(friendId)));
    strQuery.append(QString(" and userId=%1").arg(QString::number(userId)));
    QSqlQuery query(strQuery,userdb);

    if(query.next())
    {
        //该用户有此好友了，不需要添加
        qDebug()<<"好友已存在";
        return;
    }

    query.prepare("insert into FRIEND(id,userId,name) values(?,?,?)");
    query.bindValue(0,friendId);
    query.bindValue(1,userId);
    query.bindValue(2,name);

}
/**
 * @brief DataBaseMagr::AddHistoryMsg
 * 添加历史记录
 * @param userId
 * @param itemInfo
 */
void DataBaseMagr::AddHistoryMsg(const int &userId, ItemInfo *itemInfo)
{
    // 查询数据库
    QSqlQuery query("SELECT [id] FROM MSGINFO ORDER BY id DESC;", msgdb);
    int nId = 0;
    // 查询最高ID
    if (query.next()) {
        nId = query.value(0).toInt();
    }

    // 根据新ID重新创建用户
    query.prepare("INSERT INTO MSGINFO (id, userId, name, head, datetime, filesize, content, type, direction) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?);");

    query.bindValue(0, nId + 1);
    query.bindValue(1, userId);
    query.bindValue(2, itemInfo->GetName());
    query.bindValue(3, itemInfo->GetStrPixmap());
    query.bindValue(4, itemInfo->GetDatetime());
    query.bindValue(5, itemInfo->GetText());
    query.bindValue(6, itemInfo->GetFileSizeString());
    query.bindValue(7, itemInfo->GetOrientation());
    query.bindValue(8, itemInfo->GetMsgType());

    query.exec();
}
