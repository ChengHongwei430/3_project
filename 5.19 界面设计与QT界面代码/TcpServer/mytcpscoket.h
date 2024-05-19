


//是一个连接类，表示与一个客户端建立的一个连接
//包含构造析构函数
//以及对连接信号的处理函数

#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include<QTcpSocket>//将父类加入
#include<QDebug>//用于打印
#include<protocol.h>//协议的设计类文件
#include<operatedb.h>//数据库操作文件


class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT//表示支持槽函数
public:
    MyTcpSocket();
    QString getName();//用来公开获取用户名
signals:
    void offline(MyTcpSocket *myscoket);//用来删除mytcpserver链表中对应的tcp连接

public slots://公开的槽函数
    void recvMsg();//出现新的连接信号时
    void clientOfflinet();//当连接断开时

private:
    QString m_strName;//记录这一次建立这一次连接的用户名
};

#endif // MYTCPSOCKET_H
