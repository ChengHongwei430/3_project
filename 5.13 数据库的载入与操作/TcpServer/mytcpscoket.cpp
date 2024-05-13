


//是服务器端网络编程的实现函数
//这是直接建的C++类，就是包含两个文件：.h头文件和资源.cpp文件

#include "mytcpscoket.h"

///构造函数
//1、建立 完成一条新连接这个事件 和 新连接信号处理函数的连接
MyTcpSocket::MyTcpSocket()
{
    connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    //当服务器收到客户端的一条信息后，触发recvMsg函数
    //用于服务器识别信息来自哪一个客户端
}


///新连接信号处理函数
//0、设计目的是为了使对于来自不同客户端的数据使用不同的MyTcpSocket来接收，会将不同的MyTcpSocket放进一个链表里
//1、使用read()来读出信号的信息长度
//2、有了长度就可以生成一个信息的指针*pdu，可以说是把客户端的信号又解析成协议形式的信息
//3、由于是简单的连接机制，这里就在函数内部输出一下信息，本质上只是想实现客户端与服务器端的通信
void MyTcpSocket::recvMsg()
{
    //qDebug()<<this->bytesAvailable();//打印当前数据的大小

    uint uiPDULen = 0;//一个临时的长度保存
    this->read((char*)&uiPDULen,sizeof(uint));
    //读出发来的信息的前sizeof(uint)位，作为信息长度
    //其返回的是一个char指针和长度，使用&uiPDULen转成char*来接收
    //可以把read函数想象成键盘输入，read(char* A,int B),B控制读多少，A控制放到哪

    uint uiMsgLen=uiPDULen-sizeof(PDU);
    //计算信息真实长度，也可以读那一部分，但写起来很麻烦

    PDU *pdu=mkPDU(uiMsgLen);
    //有了信息真实长度，就可以建立协议信息
    //因为客户端m_tcpSocket.write((char*)pdu,pdu->uiPDULen);//将pdu作为协议信息写入发送信号
    //客户端发来的是一个m_tcpSocket信号，里面包含了协议，但已经不是纯粹的协议了
    //基于QT编程，就是为了使用里面的基本函数，例如网络编程的QTcpSocket
    //如果让我自己写，恐怕需要很久

    this->read((char*)pdu+sizeof(uint),uiPDULen-sizeof(uint));
    //把信息剩余部分读到pdu里面存放

    //pdu->uiPDULen=uiPDULen;
    //没必要把整体长度存进去，初始化时就有了

    qDebug()<<"信息类型："<<pdu->uiMsgType;//打印
    qDebug()<<"信息实际长度："<<pdu->uiMsgLen;
    qDebug()<<"信息名称："<<pdu->caData;
    qDebug()<<"信息内容："<<(char*)(pdu->caMsge);
    //其他类型的数据会被当做整型指针存储，但可以在输出时当做字符指针输出

}
