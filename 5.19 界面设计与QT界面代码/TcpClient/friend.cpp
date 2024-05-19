#include "friend.h"

Friend::Friend(QWidget *parent) : QWidget(parent)
{
    //QT的新建函数返回的就是指针
    m_pShowMsgTE= new QTextEdit;//信息显示
    m_pFriendListWidget = new QListWidget;//好友列表
    m_pInputMsgLE = new QLineEdit;//输入框

    m_pDelFriendPB = new QPushButton("删除好友");
    m_pFlushFriendPB = new QPushButton("刷新好友");
    m_pShowOnlineUserPB = new QPushButton("显示在线用户");
    m_pSearchUserPB = new QPushButton("查找用户");
    m_pMsgSendPB = new QPushButton("发送信息");
    m_pPrivateChatPB = new QPushButton("私聊用户");


    QVBoxLayout* pRightPBVBL = new QVBoxLayout;
    pRightPBVBL->addWidget(m_pDelFriendPB);
    pRightPBVBL->addWidget(m_pFlushFriendPB);
    pRightPBVBL->addWidget(m_pShowOnlineUserPB);
    pRightPBVBL->addWidget(m_pSearchUserPB);
    pRightPBVBL->addWidget(m_pPrivateChatPB);
    //QHBoxLayout* m_pFlushFriendPB;

    QHBoxLayout* pTopPBVBL = new QHBoxLayout;
    pTopPBVBL->addWidget(m_pShowMsgTE);
    pTopPBVBL->addWidget(m_pFriendListWidget);
    pTopPBVBL->addLayout(pRightPBVBL);


    QHBoxLayout* pMsgHBL = new QHBoxLayout;
    pMsgHBL->addSpacerItem(new QSpacerItem(40, 20));//加一个弹簧隔开
    pMsgHBL->addWidget(m_pInputMsgLE);
    pMsgHBL->addWidget(m_pMsgSendPB);

    m_pOnline = new Online;
    //m_pOnline->show();

    QVBoxLayout* pMain = new QVBoxLayout;
    pMain->addLayout(pTopPBVBL);
    pMain->addLayout(pMsgHBL);
    pMain->addWidget(m_pOnline);
    m_pOnline->hide();//先隐藏在线窗口

    setLayout(pMain);

    //connect(m_pShowOnlineUserPB,SIGNAL(clicked(bool)),this,SLOT(showOnline()));
    connect(m_pShowOnlineUserPB,SIGNAL(clicked()),this,SLOT(showOnline()));
    //clicked(bool)可以把按键当前的状态bool传入
    //按键m_pShowOnlineUserPB的信号，由friend对象的showOnline()函数处理

}

void Friend::showOnline()
{
    //通过点击在线用户按钮，控制界面显示和隐藏
    if(m_pOnline->isHidden()) m_pOnline->show();
    else m_pOnline->hide();
}
