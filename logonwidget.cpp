#include "logonwidget.h"
#include <QIcon>
#include <QAction>
#include <DLabel>
#include <DFontSizeManager>
#include <DCommandLinkButton>
#include <QBoxLayout>
#include <DPushButton>
#include <QLineEdit>
#include <QDesktopServices>
#include <QUrl>

LogonWidget::LogonWidget(QWidget *parent) : DDialog(parent)
{
    DLabel *label = new DLabel(this);
    label->setPixmap(QPixmap(":/images/images5.png"));

    DLabel *label1 = new DLabel(this);
    DFontSizeManager::instance()->bind(label1, DFontSizeManager::T3, QFont::DemiBold);
    label1->setText(tr("网络账户登录"));

    m_edit = new QLineEdit(this);
    m_edit->setPlaceholderText(tr("用户名/邮箱/手机号"));
    m_edit->addAction(QIcon::fromTheme("dcc_acount"),QLineEdit::LeadingPosition);
    m_edit1 = new QLineEdit(this);
    m_edit1->setPlaceholderText(tr("密码"));
    m_edit1->addAction(QIcon::fromTheme("dcc_lock"),QLineEdit::LeadingPosition);

    QHBoxLayout *hlayout = new QHBoxLayout;
    DCommandLinkButton *registerBtn = new DCommandLinkButton(tr("注册"),this);
    registerBtn->setObjectName("registerBtn");
    DCommandLinkButton *passwdBtn = new DCommandLinkButton(tr("忘记密码？"),this);
    passwdBtn->setObjectName("passwdBtn");
    connect(registerBtn, &DCommandLinkButton::clicked, this, &LogonWidget::openUrl);
    connect(passwdBtn, &DCommandLinkButton::clicked, this, &LogonWidget::openUrl);

    hlayout->addWidget(registerBtn);
    hlayout->addWidget(passwdBtn);

    DPushButton *logbtn = new DPushButton(tr("登录"),this);

    QWidget *contentWidget = new QWidget(this);
    QVBoxLayout *vlayout = new QVBoxLayout;
    contentWidget->setLayout(vlayout);
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

    addContent(contentWidget);
}

void LogonWidget::openUrl()
{
    QString url = "";
    DCommandLinkButton *btn = qobject_cast<DCommandLinkButton *>(sender());

    if ("registerBtn" == btn->objectName()) {
         url = "https://account.chinauos.com/register?lang=zh";
    } else if ("passwdBtn" == btn->objectName()) {
         url = "https://account.chinauos.com/register/support?lang=zh";
    }

    QDesktopServices::openUrl(QUrl(url));
}
