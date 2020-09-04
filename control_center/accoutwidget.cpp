#include "accoutwidget.h"
#include "userwidget.h"
#include "newaccout.h"
#include <QBoxLayout>
#include <DListView>
#include <DVerticalLine>
#include <QDebug>

AccoutWidget::AccoutWidget(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *mainlayout = new QHBoxLayout;
    this->setLayout(mainlayout);

    QVBoxLayout *vlyout = new QVBoxLayout;
    DListView *listview = new DListView;
    QStandardItemModel *itemModel = new QStandardItemModel;
    QStandardItem *account = new QStandardItem(QIcon::fromTheme("dcc_nav_accounts"),tr("yaphetshl"));
    itemModel->appendRow(account);
    listview->setModel(itemModel);

    DFloatingButton *addbtn = new DFloatingButton(DStyle::SP_IncreaseElement);
    addbtn->setFixedSize(60,60);
    addbtn->setFocusPolicy(Qt::StrongFocus);

    vlyout->addWidget(listview);
    vlyout->addWidget(addbtn);
    vlyout->setAlignment(addbtn,Qt::AlignHCenter);

    DVerticalLine *line = new DVerticalLine(this);

    UserWidget *userwidget = new UserWidget(this);

    NewAccout *newWidget = new NewAccout(this);
    newWidget->hide();

    mainlayout->addLayout(vlyout,2);
    mainlayout->addWidget(line);
    mainlayout->addWidget(userwidget,3);

    connect(addbtn,&DFloatingButton::clicked,[=](){
        userwidget->hide();
        newWidget->show();
        mainlayout->addWidget(newWidget,3);
    });

    connect(newWidget,&NewAccout::signalcancel,[=](){
        newWidget->hide();
        userwidget->show();
        mainlayout->addWidget(userwidget,3);
    });

    connect(newWidget,&NewAccout::signalNewaccout,[=](const QPixmap &pix, const QString &accout,
                                                      const QString &name, const QString &password){
        Q_UNUSED(name)
        Q_UNUSED(password)
        QStandardItem *newAccount = new QStandardItem(QIcon(pix),accout);
        itemModel->appendRow(newAccount);
    });
}
