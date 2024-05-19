#include "operatewidget.h"

OperateWidget::OperateWidget(QWidget *parent) : QWidget(parent)
{
    m_pListW = new QListWidget(this);
    m_pListW->addItem("好友");
    m_pListW->addItem("图书");

    //好友和图书窗口每次只显示一个，用堆栈窗口实现QStackedWidget，通过左边的选项控制
    m_pFriend = new Friend;
    m_pBook = new Book;

    m_psw = new QStackedWidget;
    m_psw->addWidget(m_pFriend);//默认显示第一个窗口
    m_psw->addWidget(m_pBook);

    QHBoxLayout *pMain = new QHBoxLayout;
    pMain->addWidget(m_pListW);
    pMain->addWidget(m_psw);
    //这里只是将左边的列表控件和右边的堆栈控件放到了一起，
    //但左边的切换还没有关联上右边的切换，所以需要添加信号与槽函数

    setLayout(pMain);

    connect(m_pListW,SIGNAL(currentRowChanged(int)),m_psw,SLOT(setCurrentIndex(int)));
    //将左边的列表控件和右边的堆栈控件连接，传递的参数是切换后的行号

}

OperateWidget &OperateWidget::getInstance()
{
    static OperateWidget instance;
    return instance;
}
