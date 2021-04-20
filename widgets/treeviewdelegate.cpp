#include "treeviewdelegate.h"
#include "treeitem.h"

#include <QPainter>
#include <QDebug>
#include <DApplication>
#include <DStyle>
#include <DApplicationHelper>

DWIDGET_USE_NAMESPACE

TreeViewDelegate::TreeViewDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void TreeViewDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    painter->save();
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setOpacity(1);

    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index);

    QRect rect = opt.rect;
    QFontMetrics fm(opt.font);
    QPainterPath path;
    QRect textRect = rect;

    QWidget *activeWindow = DApplication::activeWindow();
    DPalette::ColorGroup group;

    if (!(opt.state & DStyle::State_Enabled))
        group = DPalette::Disabled;
    else
        group = !activeWindow ? DPalette::Inactive : DPalette::Active;

    DStyle *style = qobject_cast<DStyle *>(DApplication::style());
    int radius = style->pixelMetric(DStyle::PM_FrameRadius, &option);

    // 设置背景色、文本色
    DApplicationHelper *dAppHelper = DApplicationHelper::instance();
    DPalette palette = dAppHelper->applicationPalette();
    QBrush background;
    QPen foreground;
    foreground.setColor(palette.color(group, DPalette::Text));
    background = palette.color(group, DPalette::ItemBackground);

    if (opt.state & DStyle::State_Enabled) {
        if (opt.state & DStyle::State_Selected) {
            QColor color;
            if (!color.isValid()) {
                DPalette palette;
                color = palette.brush(DPalette::Highlight).color();
            }

            background = color;
            foreground.setColor(palette.color(group, DPalette::HighlightedText));
        } else if (opt.state & DStyle::State_MouseOver) {
            background = palette.brush(DPalette::Button).color();
        }
    }

    path.addRoundedRect(rect, radius, radius);
    painter->fillPath(path, background);

    //判断节点
    QRect iconRect = QRect(rect.left()+10, rect.top() + 5, 20, 20);//图片区域
    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
    QIcon icon = item->icon();
    if (!icon.isNull())
        icon.paint(painter, iconRect, Qt::AlignCenter);

    // 绘制文本
    textRect.adjust(10 + 20 + 10, 0, 0, 0);
    QString text = fm.elidedText(opt.text, Qt::ElideMiddle, textRect.width());
    painter->setFont(opt.font);
    painter->drawText(textRect, Qt::TextSingleLine | static_cast<int>(opt.displayAlignment), text);
    painter->restore();
}

QSize TreeViewDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSize size = QStyledItemDelegate::sizeHint(option, index);

    return QSize(size.width(), 30);
}

