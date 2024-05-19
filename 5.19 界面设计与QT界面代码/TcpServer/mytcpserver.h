

//服务器端的连接服务类，用于监听来自客户端的连接信息，代表与客户端的连接，只能有一个类变量
//包含不使用的构造函数
//以及一个属于类的静态函数，用来实现单例模式
//一个获取连接信息的incomingConnection函数，其是父类QTcpServer的函数，当一个新连接被建立时，就会自动执行这个函数
//一个链表，保存目前已经建立的连接

#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>//一定要保存pro文件里的network
#include <QList>//链表的使用
#include "mytcpscoket.h"//将协议接收类引入

class MyTcpServer : public QTcpServer
{
    Q_OBJECT//使用信号槽

public:
    MyTcpServer();

    static MyTcpServer &getInstance();//静态函数

    void incomingConnection(qintptr handle);//父类QTcpServer的虚函数
    //当一个新连接被建立时，就会自动执行这个函数，不需要建立槽函数与信号的连接
    //需要子类重新定义，以便获得客户端连接的信息

public slots://槽函数
    void deleteSocket(MyTcpSocket* mysocket);//删除链表中的一个TCP连接的槽函数

private:
    QList<MyTcpSocket*> m_tcpScoketList;
    //一个链表，用来存放来自客户端的信号

};

#endif // MYTCPSERVER_H
