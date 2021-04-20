#include "soundwidget.h"
#include "widgets/TreeView.h"
#include "widgets/treeitem.h"
#include "widgets/treemodel.h"

#include <QVBoxLayout>

SoundWidget::SoundWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    TreeView *m_view  = new TreeView(this);

    QStringList headers;
    headers << tr("Title");
    TreeModel *m_model = new TreeModel(headers);
    m_view->setModel(m_model);

    QVector<QVariant> data = {"frist"};
    QVector<QVariant> secendData = {"secend"};
    for (int i = 0; i < 5; i++) {
        TreeItem *item = new TreeItem(data);
        item->setIcon(QIcon::fromTheme("controlcenter"));
        TreeItem *chidItem = new TreeItem(data, item);
        chidItem->setIcon(QIcon::fromTheme("controlcenter"));
        TreeItem *thirdChidItem = new TreeItem(data, chidItem);
        thirdChidItem->setIcon(QIcon::fromTheme("controlcenter"));
        TreeItem *secendChidItem = new TreeItem(secendData, item);
        secendChidItem->setIcon(QIcon::fromTheme("controlcenter"));
        item->appendChild(chidItem);
        chidItem->appendChild(thirdChidItem);
        item->appendChild(secendChidItem);
        m_model->insertItem(i, item);
    }

    layout->addWidget(m_view);
}
