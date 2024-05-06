#ifndef MYTCPSERVER_H
#define MYTCPSERVER_H

#include <QTcpServer>//一定要保存pro文件里的network

class MyTcpServer : public QTcpServer
{
    Q_OBJECT//使用信号槽

public:
    MyTcpServer();

    static MyTcpServer &getInstance();//静态函数

    void incomingConnection(qintptr handle);//父类QTcpServer的虚函数
    //需要子类重新定义，以便获得客户端连接的信息

};

#endif // MYTCPSERVER_H
