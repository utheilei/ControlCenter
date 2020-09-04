#include "userwidget.h"
#include "avatarwidget.h"
#include "settingsgroup.h"
#include "settingsitem.h"
#include "fullnameedit.h"
#include "listiconview.h"

#include <DLineEdit>
#include <QBoxLayout>
#include <DLabel>
#include <DPushButton>
#include <DWarningButton>
#include <DSwitchButton>
#include <DApplicationHelper>
#include <QScrollArea>

UserWidget::UserWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainContentLayout = new QVBoxLayout;
    mainContentLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    mainContentLayout->setMargin(0);
    setLayout(mainContentLayout);
    setFocusPolicy(Qt::ClickFocus);

    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameStyle(QFrame::NoFrame);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setContentsMargins(0, 0, 0, 0);
    mainContentLayout->addWidget(scrollArea);
    auto contentLayout = new QVBoxLayout();
    contentLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    auto tw = new QWidget(this);
    tw->setLayout(contentLayout);
    contentLayout->setSpacing(0);
    contentLayout->setContentsMargins(0, 0, 6, 0);
    scrollArea->setWidget(tw);
    //    //QColor color = pa.lightLively().color();
    //    //pa.setColor(QPalette::Button, color);
    initWidget(contentLayout);

    connect(btn,static_cast<void (AvatarWidget::*)()>(&AvatarWidget::clicked),this,&UserWidget::showAccoutView);
    connect(accoutView,&ListIconView::currentIconPath,this,&UserWidget::setUserPixmap);
}

UserWidget::~UserWidget()
{
    if(settingsGroup){
        delete settingsGroup;
        settingsGroup = Q_NULLPTR;
    }
}

void UserWidget::initWidget(QVBoxLayout *layout)
{
    accoutView = new ListIconView(this);
    accoutView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    accoutView->hide();

    btn = new AvatarWidget(QPixmap(":/images/images3.png"),this);
    btn->setFixedSize(80,80);

    DLabel *label = new DLabel(this);
    label->setText(tr("yaphetshl"));
    label->setEnabled(false);

    fullNameEdit = new FullNameEdit(this);

    QHBoxLayout *hlayout = new QHBoxLayout;
    DPushButton *passwordbtn = new DPushButton(tr("修改密码"));
    DWarningButton *deletebtn = new DWarningButton;
    deletebtn->setText(tr("删除账户"));
    deletebtn->setEnabled(false);
    hlayout->addWidget(passwordbtn);
    hlayout->addWidget(deletebtn);

    SettingsItem *autoItem = new SettingsItem(this);
    DLabel *autoLabel = new DLabel(tr("自动登录"));
    QHBoxLayout *hLayout = new QHBoxLayout;
    autoItem->setLayout(hLayout);
    hLayout->addWidget(autoLabel);
    hLayout->addStretch();
    DSwitchButton *switchbtn = new DSwitchButton(this);
    hLayout->addWidget(switchbtn);

    SettingsItem *passWordItem = new SettingsItem(this);
    DLabel *passWordLabel = new DLabel(tr("无密码登录"));
    QHBoxLayout *hLayout1 = new QHBoxLayout;
    passWordItem->setLayout(hLayout1);
    hLayout1->addWidget(passWordLabel);
    hLayout1->addStretch();
    DSwitchButton *switchbtn1 = new DSwitchButton(this);
    hLayout1->addWidget(switchbtn1);

    settingsGroup = new SettingsGroup(nullptr, SettingsGroup::GroupBackground);
    settingsGroup->setContentsMargins(0, 0, 0, 0);
    settingsGroup->layout()->setMargin(0);
    settingsGroup->appendItem(autoItem);
    settingsGroup->appendItem(passWordItem);

    layout->addSpacing(40);
    layout->addWidget(btn);
    layout->setAlignment(btn,Qt::AlignHCenter);
    layout->addWidget(label);
    layout->setAlignment(label,Qt::AlignHCenter);
    layout->addWidget(fullNameEdit);
    layout->addSpacing(30);
    layout->addWidget(accoutView);
    layout->addLayout(hlayout);
    layout->addSpacing(20);
    layout->addWidget(settingsGroup);
    layout->addStretch();
}

void UserWidget::showAccoutView()
{
    if(btn->arrowed()){
        accoutView->show();
    } else {
        accoutView->hide();
    }
}

void UserWidget::setUserPixmap(QString &iconPath)
{
    btn->setPixmap(QPixmap(iconPath));
    if(accoutView->isVisible()){
        accoutView->hide();
        btn->setArrowed(false);
    }
}
