


//客户端的主体类
//包含构造函数和析构函数
//包含加载服务器端IP地址和端口号的配置文件的函数loadConfig()
//展示与服务器连接状态的函数showConnect()
//按下按钮后的槽函数on_pushButton_clicked()
//总程序指针ui、IP地址和端口号
//最终发出的QTcpSocket信号信息m_tcpSocket

#ifndef TCPCLIENT_H
#define TCPCLIENT_H
//Ctrl s 保存

#include <QWidget>
#include <QFile>//文件类
#include <QByteArray>//字节数组
#include <QDebug>//Debug测试，主要用于测试输出值
#include <QMessageBox>//一个小的信息窗口
#include <QTcpSocket>//表示网络编程
//对应的pro文件里也要添加网络编程模块， QT       += core gui network
#include <QHostAddress>//IP地址类
#include <protocol.h>//协议设计
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QWidget
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig();//加载配置的成员函数
    //使用Alt加回车来添加定义

public slots:
    void showConnect();//定义一个槽函数，来显示与服务器的连接状态，alt加回车，建立槽函数
    void recvMsg();//接收信号


private slots:
    //void on_pushButton_clicked();

    void on_login_pb_clicked();

    void on_regist_pb_clicked();

    void on_cancel_pb_clicked();

private:

    Ui::TcpClient *ui;//总窗口或者说程序指针

    QString m_strIP;//IP地址，使用本地环回地址
    quint16 m_usPort;//端口号，使用无符号的16位整数

    QTcpSocket m_tcpSocket;//连接服务器，与服务器进行数据交互
    //QTcpSocket有默认值,是一个连接信号


};
#endif // TCPCLIENT_H











