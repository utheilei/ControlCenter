#include "networkaccout.h"
#include "logonwidget.h"

#include <DLabel>
#include <DFontSizeManager>
#include <DSuggestButton>
#include <QBoxLayout>
#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

NetworkAccout::NetworkAccout(QWidget *parent) : QWidget(parent)
{
    DLabel *label = new DLabel(this);
    label->setPixmap(QPixmap(":/images/images5.png"));

    DLabel *label1 = new DLabel(this);
    QFont font("SimHei");
    font.setBold(true);
    label1->setFont(font);
    DFontSizeManager::instance()->bind(label1, DFontSizeManager::T3);
    label1->setText(tr("网络账户登录"));

    DLabel *label2 = new DLabel(this);
    label2->setText(tr("登录网络账户后，你可以使用商店,云同步，浏览器等相关云服务功能。"));
    label2->setEnabled(false);

    DLabel *label3 = new DLabel(this);
    label3->setText(tr("目前仅支持中国大陆地区"));
    label3->setEnabled(false);

    DSuggestButton *creatbtn = new DSuggestButton(tr("登录"));
    creatbtn->setFixedSize(260,40);

    QVBoxLayout *vlayout = new QVBoxLayout;
    this->setLayout(vlayout);
    vlayout->addStretch();
    vlayout->addWidget(label);
    vlayout->setAlignment(label,Qt::AlignHCenter);
    vlayout->addWidget(label1);
    vlayout->setAlignment(label1,Qt::AlignHCenter);
    vlayout->addWidget(label2);
    vlayout->setAlignment(label2,Qt::AlignHCenter);
    vlayout->addWidget(creatbtn);
    vlayout->setAlignment(creatbtn,Qt::AlignHCenter);
    vlayout->addWidget(label3);
    vlayout->setAlignment(label3,Qt::AlignHCenter);
    vlayout->addStretch();

    connect(creatbtn,&DSuggestButton::clicked,[=](){
        LogonWidget logon;
        logon.setFixedSize(360,440);
        logon.moveToCenter();
        logon.exec();
    });
}
