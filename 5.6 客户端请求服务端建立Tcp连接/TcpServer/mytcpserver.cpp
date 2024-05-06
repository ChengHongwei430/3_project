#include "mytcpserver.h"
#include <QDebug>

MyTcpServer::MyTcpServer()
{

}

MyTcpServer &MyTcpServer::getInstance()
{
    static MyTcpServer instance;
    return instance;//所有的类变量共用一个静态成员变量
    //我认为这不是单例模式
    //单例模式应该是把对于一个类只能有一个对象，比如把构造函数放到私有里，再不允许友元
    //这里只能说是不允许构造，只允许通过调用getInstance构造，是一种人为约束
}

void MyTcpServer::incomingConnection(qintptr handle)
{
    qDebug() << "收到新的客户端连接！";
}
