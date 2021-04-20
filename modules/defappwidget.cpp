#include "defappwidget.h"
#include "widgets/SettingWidget.h"
#include "HoverDelegate.h"

#include <QStandardItemModel>
#include <QHBoxLayout>

DefAppWidget::DefAppWidget(QWidget *parent) : IWindow(parent)
{
    init();

    QHBoxLayout *hLayout = static_cast<QHBoxLayout *>(this->layout());
    hLayout->setContentsMargins(20, 10, 20, 10);
    hLayout->setSpacing(10);
    hLayout->insertWidget(0, m_leftWidget);
    hLayout->addWidget(m_rightWidget);
}

void DefAppWidget::initLeftWidget()
{
    m_leftWidget = new SettingWidget(this);

    QStandardItemModel *m_model = new QStandardItemModel(this);
    m_leftView = new DListView(this);
    m_hoverDelegate = new HoverDelegate(m_leftView);
    m_leftView->setFrameShape(QFrame::NoFrame);
    m_leftView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_leftView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_leftView->setBackgroundType(DStyledItemDelegate::ClipCornerBackground);
    m_leftView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_leftView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_leftView->setItemDelegate(m_hoverDelegate);
    m_leftView->setSelectionMode(QAbstractItemView::ExtendedSelection); // 设置支持多行选择（shift/ctrl）
    m_leftView->setSelectionBehavior(QAbstractItemView::SelectRows); // 设置点击选中整行
    m_leftView->setModel(m_model);
    m_leftWidget->setWidget(m_leftView);

    for (int i = 1; i< 20 ; i++) {
        auto item = new DStandardItem;
        item->setText(QString("Left-QAbstractItemView-Model-Test-%1").arg(i));
        item->setIcon(QIcon::fromTheme("dcc_close"));
        m_model->appendRow(item);
    }
}

void DefAppWidget::initRigthWidget()
{
    m_rightWidget = new SettingWidget(this);

    QStandardItemModel *model = new QStandardItemModel(this);
    m_rightView = new DListView(this);
    HoverDelegate *hoverDelegate = new HoverDelegate(m_rightView);
    m_rightView->setFrameShape(QFrame::NoFrame);
    m_rightView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_rightView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_rightView->setBackgroundType(DStyledItemDelegate::ClipCornerBackground);
    m_rightView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_rightView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_rightView->setItemDelegate(hoverDelegate);
    m_rightView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_rightView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_rightView->setModel(model);
    m_rightWidget->setWidget(m_rightView);

    for (int i = 1; i< 20 ; i++) {
        auto item = new DStandardItem;
        item->setText(QString("Right-QAbstractItemView-Model-Test-%1").arg(i));
        item->setSelectable(false);
        model->appendRow(item);
    }
}

void DefAppWidget::initConnection()
{
    connect(m_hoverDelegate, &HoverDelegate::stateChanged, [=](const QModelIndex &index){
        qDebug() << index;
        m_leftView->model()->removeRow(index.row());
    });

    connect(m_rightView, &DListView::clicked, [=](const QModelIndex &index){
        for (int i = 0; i < m_rightView->model()->rowCount() ; i++) {
            QModelIndex index = m_rightView->model()->index(i, 0);
            m_rightView->model()->setData(index, Qt::Unchecked, Qt::CheckStateRole);
        }

        m_rightView->model()->setData(index, Qt::Checked, Qt::CheckStateRole);
    });
}
