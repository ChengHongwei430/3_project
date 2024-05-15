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
    //处理注册信息


private:
    QSqlDatabase m_db;//数据库

public slots://公共槽函数


signals:

};

#endif // OPERATEDB_H
