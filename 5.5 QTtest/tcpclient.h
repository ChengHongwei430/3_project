#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QWidget>
#include <QProcess>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class TCPClient; }
QT_END_NAMESPACE

class TCPClient : public QWidget//继承自类QWidget
{
    Q_OBJECT//槽相关宏定义

public:
    TCPClient(QWidget *parent = nullptr);//构造函数，默认是空
    ~TCPClient();//析构函数

private slots:
    void on_pushButton1_clicked();//在设计功能之后，出现的槽函数
    void testclose();

private:
    Ui::TCPClient *ui;//私有的成员变量,表示指向界面的指针
};
#endif // TCPCLIENT_H
