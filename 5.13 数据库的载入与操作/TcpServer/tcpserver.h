


//服务器端的主体类，代表服务器窗口
//包含构造析构函数，加载配置函数

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QWidget>
#include <QFile>//文件类
#include <mytcpserver.h>
#include <QByteArray>//字节数组
#include <QDebug>//Debug测试，主要用于测试输出值
#include <QMessageBox>//一个小的信息窗口
#include <QTcpSocket>//表示网络编程
//对应的pro文件里也要添加网络编程模块， QT       += core gui network
#include <QHostAddress>//IP地址类

QT_BEGIN_NAMESPACE
namespace Ui { class TcpServer; }
QT_END_NAMESPACE

class TcpServer : public QWidget
{
    Q_OBJECT

public:
    TcpServer(QWidget *parent = nullptr);
    ~TcpServer();

    void loadConfig();//加载配置文件

private:
    Ui::TcpServer *ui;

    QString m_strIP;//IP地址，使用本地环回地址
    quint16 m_usPort;//端口号，使用无符号的16位整数

};
#endif // TCPSERVER_H
