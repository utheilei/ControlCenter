#include "personalizationwidget.h"
#include "commonwidget.h"

#include <DVerticalLine>
#include <QBoxLayout>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QDebug>

PersonalizationWidget::PersonalizationWidget(QWidget *parent) : IWindow(parent)
{
    init();

    QHBoxLayout *hLayout = static_cast<QHBoxLayout *>(this->layout());
    hLayout->insertWidget(0,listView,1);
    hLayout->addWidget(stackedWidget, 2);
}

void PersonalizationWidget::initLeftWidget()
{
    listView = new DListView(this);
    QStandardItemModel *itemModel = new QStandardItemModel(this);
    QStandardItem *commomItem = new QStandardItem();
    commomItem->setIcon(QIcon(":/images/dcc_common_32px.svg"));
    commomItem->setText(tr("通用"));
    commomItem->setData(ConmmonItem, Qt::UserRole+1000);
    itemModel->appendRow(commomItem);

    QStandardItem *iconItem = new QStandardItem();
    iconItem->setIcon(QIcon(":/images/dcc_Icon_theme_32px.svg"));
    iconItem->setText(tr("图标主题"));
    iconItem->setData(IconItem,Qt::UserRole+1000);
    itemModel->appendRow(iconItem);

    QStandardItem *cursorItem = new QStandardItem();
    cursorItem->setIcon(QIcon(":/images/dcc_cursor_theme_32px.svg"));
    cursorItem->setText(tr("光标主题"));
    cursorItem->setData(CursorItem, Qt::UserRole+1000);
    itemModel->appendRow(cursorItem);

    QStandardItem *fontItem = new QStandardItem();
    fontItem->setIcon(QIcon(":/images/dcc_Font_32px.svg"));
    fontItem->setText(tr("字体"));
    fontItem->setData(FontItem, Qt::UserRole+1000);
    itemModel->appendRow(fontItem);

    listView->setModel(itemModel);
}

void PersonalizationWidget::initRigthWidget()
{
    stackedWidget = new QStackedWidget(this);
    CommonWidget *commonWidget = new CommonWidget(this);
    stackedWidget->addWidget(commonWidget);
    listWidget.insert(ConmmonItem,commonWidget);
    stackedWidget->setCurrentIndex(0);
}

void PersonalizationWidget::initConnection()
{
    connect(listView,&DListView::clicked,this,&PersonalizationWidget::onChanged);
}

void PersonalizationWidget::onChanged(const QModelIndex &index)
{
    QWidget *widget = listWidget.value(index.data(Qt::UserRole+1000).toInt());
    stackedWidget->setCurrentWidget(widget);
    qDebug() << index.data(Qt::UserRole+1000).toInt() << index.data().toString();
}
