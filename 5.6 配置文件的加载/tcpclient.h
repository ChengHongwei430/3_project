#ifndef TCPCLIENT_H
#define TCPCLIENT_H
//Ctrl s 保存

#include <QMainWindow>
#include <QFile>//文件类
#include <QByteArray>//字节数组
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TcpClient; }
QT_END_NAMESPACE

class TcpClient : public QMainWindow
{
    Q_OBJECT

public:
    TcpClient(QWidget *parent = nullptr);
    ~TcpClient();
    void loadConfig();//加载配置的成员函数
    //使用Alt加回车来添加定义

private:
    Ui::TcpClient *ui;
    QString m_strIP;//IP地址，使用本地环回地址
    quint16 m_usPort;//端口号，使用无符号的16位整数

};
#endif // TCPCLIENT_H
