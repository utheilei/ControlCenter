#include "listiconview.h"
#include "delegate.h"

#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>
#include <QFileDialog>

ListIconView::ListIconView(QWidget *parent)
    : DListView(parent)
    , m_model(new QStandardItemModel(this))
    , m_itemDelegate(new Delegate(this))
{
    init();
    initItems();

    connect(this, &DListView::clicked, this, &ListIconView::onItemClicked);
}

void ListIconView::init()
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setViewMode(ViewMode::IconMode);
    setDragDropMode(QAbstractItemView::NoDragDrop);
    setDragEnabled(false);
    setSpacing(20);
    setResizeMode(DListView::Adjust);
    setFrameShape(QFrame::NoFrame);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setItemDelegate(m_itemDelegate);
    setModel(m_model);
}

void ListIconView::initItems()
{
    QString iconPath = "";
    for (int j=0;j<2;j++) {
        for (int i=0;i<5;i++) {
            iconPath = QString(":/images/images%1.png").arg(i);
            if(i==0)
                iconPath = QString(":/images/images.png");
            addItem(iconPath, AddItemMethod::AddItem);
        }
    }

    iconPath.clear();
    addItem(iconPath, AddItemMethod::AddItem);
}

void ListIconView::addItem(QString &iconPath, AddItemMethod method)
{
    QStandardItem *item = new QStandardItem();
    item->setData(QVariant::fromValue(QPixmap(iconPath)), Qt::DecorationRole);
    item->setData(iconPath, ListIconView::SaveAvatarRole);
    item->setData(m_size, Qt::SizeHintRole);

    if (AddItemMethod::AddItem == method) {
        m_model->appendRow(item);
    } else {
        m_model->insertRow(m_model->rowCount()-1,item);
    }
}

void ListIconView::onItemClicked(const QModelIndex &index)
{
    auto filepath = index.data(SaveAvatarRole).toString();

    if(filepath.isEmpty()){
        QString name = QFileDialog::getOpenFileName(Q_NULLPTR,
                                                    tr("图片"),"../","(*.png *.jpg *.bmp *.svg)");
        if(!name.isEmpty())
            addItem(name,AddItemMethod::InsnsertItem);
        return;
    }

    QIcon icon = index.data(Qt::DecorationRole).value<QIcon>();
    emit currentIconPath(filepath);
    emit currentIcon(icon);

    //    if (index.data(Qt::CheckStateRole) == Qt::Checked)
    //        return;

    //    for (int i=0;i<m_model->rowCount();i++) {
    //        m_model->item(i,0)->setCheckState(Qt::Unchecked);
    //    }

    //    QStandardItem *item = m_model->itemFromIndex(index);
    //    item->setCheckState(Qt::Checked);
}
