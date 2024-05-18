


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

    //incomingConnection是父类设置的虚函数，在对象建立时，一定会执行，所以连接函数可以写在这里
    connect(pTcpSocket,SIGNAL(offline(MyTcpSocket*)),this,SLOT(deleteSocket(MyTcpSocket*)));

}

///删除槽函数
void MyTcpServer::deleteSocket(MyTcpSocket* mysocket)
{
    for(QList<MyTcpSocket*>::iterator it =m_tcpScoketList.begin();it!=m_tcpScoketList.end();++it){
        //使用迭代器遍历链表
        if(mysocket==*it){
            //*it->deleterLater();
            mysocket->deleteLater();
            //删除迭代器所指的MyTcpSocket对象
            //deleteLater适用于需要延迟删除对象的场景，特别是在槽函数中需要删除与信号关联的对象时。
            //主要是客户端在关闭时MyTcpSocket（其父类）本身也会析构，会再次尝试析构，重复释放程序就会崩溃
            *it=NULL;
            m_tcpScoketList.erase(it);
            break;
            //首先存在一个MyTcpSocket对象，其次m_tcpScoketList还存在一个指向这个对象的指针
            //这两个都要删除
        }
    }
    for(int i=0;i<m_tcpScoketList.size();++i){
        qDebug()<<m_tcpScoketList[i]->getName();//打印出当前链表中的建立连接的用户们
    }
}
