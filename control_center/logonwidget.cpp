#include "logonwidget.h"
#include <QIcon>
#include <QAction>
#include <DLabel>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <QBoxLayout>
#include <DPushButton>

LogonWidget::LogonWidget(QWidget *parent) : DWidget(parent)
{
//     edit = new QLineEdit(this);
//     QAction *action = edit->addAction(QIcon(":/images/images6.png"),QLineEdit::LeadingPosition);
    DLabel *label = new DLabel(this);
    label->setPixmap(QPixmap(":/images/images5.png"));

    DLabel *label1 = new DLabel(this);
    DFontSizeManager::instance()->bind(label1, DFontSizeManager::T3, QFont::DemiBold);
    label1->setText(tr("网络账户登录"));

    m_edit = new DLineEdit(this);
    m_edit->lineEdit()->setPlaceholderText(tr("用户名/邮箱/手机号"));
    m_edit1 = new DLineEdit(this);
    m_edit1->lineEdit()->setPlaceholderText(tr("密码"));

    QHBoxLayout *hlayout = new QHBoxLayout;
    DCommandLinkButton *registerbtn = new DCommandLinkButton(tr("注册"),this);
    DCommandLinkButton *btn = new DCommandLinkButton(tr("忘记密码？"),this);
    hlayout->addWidget(registerbtn);
    hlayout->addWidget(btn);

    DPushButton *logbtn = new DPushButton(tr("登录"),this);

    QVBoxLayout *vlayout = new QVBoxLayout;
    this->setLayout(vlayout);
    vlayout->setContentsMargins(30,20,30,20);
    vlayout->addWidget(label);
    vlayout->setAlignment(label,Qt::AlignHCenter);
    vlayout->addWidget(label1);
    vlayout->setAlignment(label1,Qt::AlignHCenter);
    vlayout->addWidget(m_edit);
    vlayout->addWidget(m_edit1);
    vlayout->addLayout(hlayout);
    vlayout->setAlignment(hlayout,Qt::AlignRight);
    vlayout->addStretch();
    vlayout->addWidget(logbtn);
}
