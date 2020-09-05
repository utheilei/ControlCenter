#include "iconthemewidget.h"
#include "widgets/iconwidget.h"

#include <DStandardItem>

IconThemeWidget::IconThemeWidget(QWidget *parent) : ListWidget(parent)
{
    connect(this,&IconThemeWidget::clicked,this,&IconThemeWidget::checkItem);
}

void IconThemeWidget::init()
{
    QList<QList<QIcon>> list;
    QList<QIcon> papirusList = {QIcon::fromTheme("dcc_file_dark"),QIcon::fromTheme("dcc_music_dark"),
                         QIcon::fromTheme("dcc_pixmap_dark"),QIcon::fromTheme("dcc_movie_dark"),
                         QIcon::fromTheme("dcc_browser_dark"),QIcon::fromTheme("dcc_control_dark")};
    QList<QIcon> bloomList = {QIcon::fromTheme("dcc_file_bloom"),QIcon::fromTheme("dcc_music_bloom"),
                         QIcon::fromTheme("dcc_pixmap_bloom"),QIcon::fromTheme("dcc_movie_bloom"),
                         QIcon::fromTheme("dcc_browser_bloom"),QIcon::fromTheme("dcc_control_bloom")};
    QList<QIcon> classList = {QIcon::fromTheme("dcc_file_class"),QIcon::fromTheme("dcc_music_class"),
                         QIcon::fromTheme("dcc_pixmap_class"),QIcon::fromTheme("dcc_movie_class"),
                         QIcon::fromTheme("dcc_browser_class"),QIcon::fromTheme("dcc_control_class")};
    list << papirusList << bloomList << classList << classList << bloomList;

    QList<QString> strList = {"Papirus","bloom","bloom-classic","bloom-classic-dark","bloom-dark"};

    for (int i=0;i<strList.length();i++) {
        IconWidget *widget = new IconWidget(this);
        widget->setIconSize(QSize(50, 50));
        widget->setIcon(list[i]);
        widget->setSpacing(10);
        addIconItem(strList[i], widget);
    }

    setItemMargins(QMargins(20,10,20,20));
}

void IconThemeWidget::checkItem(const QModelIndex &index)
{
    QStandardItem *item = itemModel()->itemFromIndex(index);
    if (Q_NULLPTR != item)
        item->setCheckState(Qt::Checked);

    for (int i=0;i<itemModel()->rowCount();i++) {
        if (itemModel()->index(i,0) == index)
            continue;

        QStandardItem *item = itemModel()->item(i,0);
        if (Q_NULLPTR != item)
            item->setCheckState(Qt::Unchecked);
    }
}

void IconThemeWidget::addIconItem(QString text, QWidget *widget)
{
    DViewItemActionList actionList;

    DStandardItem *item = new DStandardItem();
    item->setText(text);
    DViewItemAction *action = new DViewItemAction();
    action->setWidget(widget);
    actionList.append(action);
    item->setActionList(Qt::Edge::BottomEdge, actionList);

    itemModel()->appendRow(item);
}
