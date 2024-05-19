#ifndef FRIEND_H
#define FRIEND_H

#include <QWidget>//下面全是布局以及控件
#include <QTextEdit>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSpacerItem>
//弹簧QHorizontalSpacer的控件
//弹簧不需要添加成员变量，直接new QSpacerItem(40, 20)就行

#include "online.h"//在线用户界面

class Friend : public QWidget
{
    Q_OBJECT
public:
    explicit Friend(QWidget *parent = nullptr);

signals:

public slots:
    void showOnline();

private:
    QTextEdit* m_pShowMsgTE;
    QListWidget* m_pFriendListWidget;
    QLineEdit* m_pInputMsgLE;

    QPushButton* m_pDelFriendPB;
    QPushButton* m_pFlushFriendPB;
    QPushButton* m_pShowOnlineUserPB;
    QPushButton* m_pSearchUserPB;
    QPushButton* m_pMsgSendPB;
    QPushButton* m_pPrivateChatPB;

    Online *m_pOnline;

};

#endif // FRIEND_H
