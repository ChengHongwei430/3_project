#ifndef OPERATEDB_H
#define OPERATEDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

class OperateDB : public QObject
{
    Q_OBJECT
public:
    explicit OperateDB(QObject *parent = nullptr);
    static OperateDB& getInstance();//静态函数，可以直接使用类来调用
    void init();
    ~OperateDB();

    bool handleRegist(const char* name ,const char* pwd);
    //处理注册信息，数据库添加记录，用户名不能重名

    bool handleLogin(const char* name ,const char* pwd);
    //处理登录信息，查询数据库，检查在线状态

    void handleOffline(const char* name);
    //当连接断开时，修改用户在线状态


private:
    QSqlDatabase m_db;//数据库

public slots://公共槽函数


signals:

};

#endif // OPERATEDB_H
