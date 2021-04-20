#include "TreeView.h"
#include "treeviewdelegate.h"
#include "treeitem.h"

#include <DLabel>
#include <DFontSizeManager>
#include <DApplication>

#include <QHeaderView>
#include <QKeyEvent>
#include <QHBoxLayout>
#include <DApplicationHelper>

class TreeViewPrivate
{
public:
    TreeViewPrivate(TreeView *q) : q_ptr(q) {}
    ~TreeViewPrivate() {}

    void init();

private:
    void initUi();

private:
    Q_DECLARE_PUBLIC(TreeView)
    TreeView *const q_ptr = Q_NULLPTR;
};

void TreeViewPrivate::init()
{
    initUi();
}

void TreeViewPrivate::initUi()
{
    Q_Q(TreeView);

    TreeViewDelegate *delegate = new TreeViewDelegate(q);
    q->setItemDelegate(delegate);

    q->setVerticalScrollMode(QAbstractItemView::ScrollMode::ScrollPerItem);
    q->setFrameShape(QFrame::NoFrame);
    q->setSelectionMode(QAbstractItemView::SingleSelection);
    q->setSelectionBehavior(QAbstractItemView::SelectRows);
    q->setEditTriggers(QAbstractItemView::NoEditTriggers);
    q->header()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    q->header()->setDefaultSectionSize(200);
    q->header()->setStretchLastSection(true);
    q->header()->setSectionsMovable(false);
    q->setSortingEnabled(true);
    q->viewport()->setAutoFillBackground(true);

    QVBoxLayout *layout = new QVBoxLayout();
    q->setLayout(layout);
}

TreeView::TreeView(QWidget *parent)
    : DTreeView(parent)
    , d_ptr(new TreeViewPrivate(this))
{
    Q_D(TreeView);

    d->init();
}

TreeView::~TreeView()
{
    Q_D(TreeView);

    delete d;
}

void TreeView::keyPressEvent(QKeyEvent *event)
{
    DTreeView::keyPressEvent(event);

    if (event->key() == Qt::Key_Up || event->key() == Qt::Key_Down)
        emit clicked(currentIndex());
}

void TreeView::drawBranches(QPainter *painter, const QRect &rect, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setOpacity(1);

    TreeItem * node = static_cast<TreeItem *>(index.internalPointer());
    bool hasChild = node->childCount() > 0;
    bool expaned = isExpanded(index);
    QRect iconRect = rect;
    iconRect.setX(rect.x() + (rect.width()-15)/2);
    iconRect.setY(rect.y() + (rect.height()-15)/2);
    iconRect.setWidth(15);
    iconRect.setHeight(15);

    DApplicationHelper *dAppHelper = DApplicationHelper::instance();
    DPalette palette = dAppHelper->applicationPalette();
    QBrush background = palette.color(DPalette::Base);

    QPainterPath path;
    path.addRect(rect);
    painter->fillPath(path, background);

    QIcon icon;
    if (expaned) {
        if (hasChild)
            icon = QIcon::fromTheme("dcc_expand");
    } else {
        if (hasChild)
            icon = QIcon::fromTheme("dcc_collapse");
    }

    if (!icon.isNull()) {
        icon.paint(painter, iconRect, Qt::AlignCenter);
    }

    painter->restore();
}

void TreeView::updateContent()
{
    updateGeometries();
}
