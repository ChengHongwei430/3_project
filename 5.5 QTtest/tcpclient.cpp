#include "tcpclient.h"
#include "ui_tcpclient.h"

///构造函数
TCPClient::TCPClient(QWidget *parent)
    : QWidget(parent)//这里是默认初始化的部分
    //QWidget = parent
    , ui(new Ui::TCPClient)
    //ui = new Ui::TCPClient
{
    ui->setupUi(this);

    ///其他三种信号与槽的连接方式：直接写一个具有特定名称的函数///
    //2、作用是将其他的信号和已经有的槽函数连接
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(on_pushButton1_clicked()));
    //信号来源，信号类型，信号处理者，信号处理函数
    //信号处理者是处理函数所属的类，这里是on_pushButton1_clicked所属的TCPClient

    //3、使用地址形式表示信号
    connect(ui->pushButton2,&QPushButton::clicked,this,&TCPClient::testclose);
    //connect(ui->pushButton2,&QPushButton::clicked,this,SLOT(testclose()));//不能执行
    //都用槽地址可以，也可以都使用地址，但一样一个就不行

    //4、当函数内容少，而且只使用一次时，可以直接写在connect里
    connect(ui->pushButton3,&QPushButton::clicked,[this](){
        QMessageBox::information(this,"信息","感谢浏览！");
    });
    //connect(ui->lineEdit,SIGNAL(returnPressed()),[this](){
        //QMessageBox::information(this,"信息","感谢浏览！");
    //});
    //我测试了，不能用SIGNAL来写前一部分

}

///析构函数
TCPClient::~TCPClient()
{
    delete ui;
}

///1、第一种信号与槽的连接方式：直接写一个具有特定名称的函数
void TCPClient::on_pushButton1_clicked()
{
    //打开line edit 指定的界面//

    //获取line edit 的数据//
    QString program=ui->lineEdit->text();
    //使用ui指针找到line edit 的文本数据

    //创建process对象，是一个进程操作，来启动一个进程//
    QProcess *myProcess =new QProcess(this);
    myProcess->start(program);
    //使用这个进程去启动界面，例如可以打开notepad记事本

}

///不属于特定名称的函数
void TCPClient::testclose()
{
    //关闭界面//
    this->close();

}
