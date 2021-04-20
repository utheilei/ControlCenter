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
    QVector<QVariant> data1 = {"secend"};
    for (int i=0;i<5;i++) {
        TreeItem *item = new TreeItem(data);
        item->setIcon(QIcon::fromTheme("controlcenter"));
        TreeItem *chidItem = new TreeItem(data, item);
        chidItem->setIcon(QIcon::fromTheme("controlcenter"));
        TreeItem *chidItem3 = new TreeItem(data, chidItem);
        chidItem3->setIcon(QIcon::fromTheme("controlcenter"));
        TreeItem *chidItem1 = new TreeItem(data1, item);
        chidItem1->setIcon(QIcon::fromTheme("controlcenter"));
        item->appendChild(chidItem);
        chidItem->appendChild(chidItem3);
        item->appendChild(chidItem1);
        m_model->insertItem(i, item);
    }

    layout->addWidget(m_view);
}
