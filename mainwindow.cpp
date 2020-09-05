#include "mainwindow.h"
#include "listwidget.h"
#include "accoutwidget.h"
#include "networkaccout.h"
#include "personalizationwidget.h"
#include "titleswidget.h"
#include "datetimewidget.h"

#include <DMenu>
#include <DFrame>
#include <DSearchEdit>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : DMainWindow(parent)
    ,m_stackedWidget(new QStackedWidget(this))
    ,listwidget(new ListWidget(this))
    ,m_mainWidget(new QStackedWidget(this))
    ,m_titlesWidget(new TitlesWidget(this))
{
    listwidget->init();

    m_titlebar = this->titlebar();
    m_titlebar->setDisableFlags(Qt::WindowMinimizeButtonHint
                              | Qt::WindowMaximizeButtonHint
                              | Qt::WindowSystemMenuHint);
    m_titlebar->setAutoHideOnFullscreen(true);
    m_titlebar->setIcon(QIcon::fromTheme("controlcenter"));

    DMenu *pDMenu = new DMenu;
    QAction *action(new QAction(tr("Help"), this));
    pDMenu->addAction(action);
    m_titlebar->setMenu(pDMenu);

    pDIconButtonLeft = new DIconButton(DStyle::SP_ArrowLeft);
    pDIconButtonLeft->setEnabled(false);
    m_titlebar->addWidget(pDIconButtonLeft,Qt::AlignLeft);

    DSearchEdit *searchEdit = new DSearchEdit(m_titlebar);
    searchEdit->setMinimumWidth(345);
    m_titlebar->addWidget(searchEdit,Qt::AlignCenter);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    QWidget *centerWidget = new QWidget(this);
    centerWidget->setLayout(mainLayout);
    setCentralWidget(m_mainWidget);

    QWidget *titleWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout;
    titleWidget->setLayout(layout);
    layout->addSpacing(80);
    layout->addWidget(m_titlesWidget);

    m_mainWidget->addWidget(titleWidget);
    m_mainWidget->addWidget(centerWidget);
    m_mainWidget->setCurrentIndex(0);

    initContent();

    DFrame *frame = new DFrame(this);
    QVBoxLayout *vLayout = new QVBoxLayout;
    frame->setLayout(vLayout);
    vLayout->setContentsMargins(0,0,0,0);
    vLayout->addWidget(m_stackedWidget);

    m_stackedWidget->setCurrentIndex(0);
    mainLayout->addWidget(listwidget,1);
    mainLayout->addSpacing(5);
    mainLayout->addWidget(frame,4);

    initConnection();
}

void MainWindow::initContent()
{
    AccoutWidget *awidget = new AccoutWidget(this);
    m_stackedWidget->addWidget(awidget);
    m_listWidget.insert(tr("account"),awidget);

    NetworkAccout *nwaWidget = new NetworkAccout(this);
    m_stackedWidget->addWidget(nwaWidget);
    m_listWidget.insert(tr("cloudsync"),nwaWidget);

    PersonalizationWidget *personalizationWidget = new PersonalizationWidget(this);
    m_stackedWidget->addWidget(personalizationWidget);
    m_listWidget.insert(tr("personalization"),personalizationWidget);

    DateTimeWidget *dateTimeWidget = new DateTimeWidget(this);
    m_stackedWidget->addWidget(dateTimeWidget);
    m_listWidget.insert(tr("datetime"),dateTimeWidget);
}

void MainWindow::initConnection()
{
    connect(listwidget, static_cast<void (DListView::*)(const QModelIndex &)>(&DListView::currentChanged),
            this, &MainWindow::slotsetWidget);

    connect(m_titlesWidget,&DListView::clicked,this,&MainWindow::onChangeWidget);

    connect(pDIconButtonLeft,&DIconButton::clicked,[=](){
        m_mainWidget->setCurrentIndex(0);
        pDIconButtonLeft->setEnabled(false);
    });
}

void MainWindow::slotsetWidget(const QModelIndex &previous)
{
    QWidget *widget =  m_listWidget.value(listwidget->currentIndex().data().toString());
    m_stackedWidget->setCurrentWidget(widget);

    qDebug()<<previous.data().toString() << listwidget->currentIndex().data().toString();
}

void MainWindow::onChangeWidget(const QModelIndex &index)
{
    m_mainWidget->setCurrentIndex(1);
    pDIconButtonLeft->setEnabled(true);

    QModelIndex currentIndex = listwidget->model()->index(index.row(),0);
    listwidget->setCurrentIndex(currentIndex);
}
