


//服务器端的连接服务类，用于监听来自客户端的连接信息

#include "mytcpserver.h"
#include <QDebug>

MyTcpServer::MyTcpServer()
{
}

MyTcpServer &MyTcpServer::getInstance()
//0、当做MyTcpServer的构造函数来看就行
//1、只能有一个服务器的服务在执行

{
    static MyTcpServer instance;
    return instance;//所有的类变量共用一个静态成员变量
    //我认为这不是单例模式
    //单例模式应该是把对于一个类只能有一个对象，比如把构造函数放到私有里，再不允许友元
    //这里只能说是不允许构造，只允许通过调用getInstance构造，是一种人为约束
}


void MyTcpServer::incomingConnection(qintptr socketDescriptor)
//0、当出现一个新连接时，会调用这个虚函数
//1、当建立一个新连接后，就连接对象放到链表里
{
    qDebug() << "收到新的客户端连接！";

    MyTcpSocket *pTcpSocket = new MyTcpSocket;//产生一个连接对象

    pTcpSocket->setSocketDescriptor(socketDescriptor);//将与客户端的连接保存到通讯

    m_tcpScoketList.append(pTcpSocket);//放入连接的链表
}
