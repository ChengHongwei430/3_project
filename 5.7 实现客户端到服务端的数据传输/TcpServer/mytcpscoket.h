


//是一个连接类，表示与一个客户端建立的一个连接
//包含构造析构函数
//以及对连接信号的处理函数

#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include<QTcpSocket>//将父类加入
#include<QDebug>//用于打印
#include<protocol.h>//协议的设计类文件

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT//表示支持槽函数
public:
    MyTcpSocket();

public slots://公开的槽函数
    void recvMsg();//
};

#endif // MYTCPSOCKET_H
