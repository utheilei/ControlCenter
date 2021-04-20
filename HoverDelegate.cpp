#include "HoverDelegate.h"

#include <DApplication>
#include <DApplicationHelper>
#include <DStyle>
#include <DListView>

#include <QMouseEvent>
#include <QPainter>

HoverDelegate::HoverDelegate(QAbstractItemView *parent)
    : DStyledItemDelegate(parent)
{
    parent->viewport()->installEventFilter(this);
    setItemSpacing(2);
}

void HoverDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    painter->save();
    painter->setRenderHints(QPainter::Antialiasing);
    painter->setOpacity(1);

    QStyleOptionViewItem opt = option;

    // 初始化样式
    DStyledItemDelegate::initStyleOption(&opt, index);

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
    QRect rect = opt.rect;
    QRect textRect = rect;
    textRect = rect;
    textRect.setX(textRect.x() + m_margins);

    // DPalette::Base前景色   DPalette::AlternateBase背景色
    bool hasAlternatefeature = opt.features & QStyleOptionViewItem::Alternate;
    background = palette.color(group, hasAlternatefeature ? DPalette::Base : DPalette::AlternateBase);

    if (opt.state & DStyle::State_Enabled) {
        if (opt.state & DStyle::State_Selected) {
            QColor color;
            if (!color.isValid()) {
                DPalette palette;
                color = palette.brush(DPalette::Highlight).color();
            }

            background = color;
            foreground.setColor(palette.color(group, DPalette::HighlightedText));
            if (index.data(Qt::DecorationRole).isValid())
                textRect.setWidth(rect.width() - m_margins * 3 - 22);
        } else if (opt.state & DStyle::State_MouseOver) {
            background = palette.brush(DPalette::Button).color();
            if (index.data(Qt::DecorationRole).isValid())
                textRect.setWidth(rect.width() - m_margins * 3 - 22);
        }
    }

    QPainterPath path;
    QPainterPath clipPath;

    if (index.model()->rowCount() == 1) { //绘制只有一个listview
        clipPath.addRoundedRect(rect.x(), rect.y(), rect.width(), rect.height(), radius, radius);
        painter->setClipPath(clipPath);
    } else {
        if (index.row() == 0) { //绘制listview上边二个角为圆角,下面二个角为直角
            QPainterPath rectPath;
            QPainterPath roundedPath;
            roundedPath.addRoundedRect(rect.x(), rect.y(), rect.width(), rect.height() * 2, radius, radius);
            rectPath.addRect(rect.x(), rect.y() + rect.height(), rect.width(), rect.height());
            clipPath = roundedPath.subtracted(rectPath);
            painter->setClipPath(clipPath);
        } else if (index.row() == index.model()->rowCount() - 1) { //绘制listview上边二个角为直角,下面二个角为圆角
            QPainterPath rectPath;
            QPainterPath roundedPath;
            roundedPath.addRoundedRect(rect.x(), rect.y() - rect.height(), rect.width(), rect.height() * 2, radius,
                                       radius);
            rectPath.addRect(rect.x(), rect.y() - rect.height(), rect.width(), rect.height());
            clipPath = roundedPath.subtracted(rectPath);
            painter->setClipPath(clipPath);
        } else { //绘制listview上下二个角都为直角
            clipPath.addRect(rect.x(), rect.y(), rect.width(), rect.height());
            painter->setClipPath(clipPath);
        }
    }

    path.addRect(rect);
    painter->fillPath(path, background);

    if (opt.features & QStyleOptionViewItem::HasCheckIndicator) {
        QStyleOptionViewItem option(opt);

        QRect iconRect = iconLocationRect(rect, QSize(m_checkWidth, m_checkWidth));
        option.rect = iconRect;
        option.state = option.state & ~QStyle::State_HasFocus;

        switch (opt.checkState) {
        case Qt::Unchecked:
            option.state |= QStyle::State_Off;
            textRect.setWidth(rect.width());
            break;
        case Qt::PartiallyChecked:
            option.state |= QStyle::State_NoChange;
            break;
        case Qt::Checked:
            option.state |= QStyle::State_On;
            textRect.setWidth(rect.width() - m_margins * 3 - m_checkWidth);
            break;
        }

        style->drawPrimitive(QStyle::PE_IndicatorViewItemCheck, &option, painter, activeWindow);
    }

    painter->setPen(foreground);
    // 绘制文本
    QFontMetrics font(opt.font);
    QString text = font.elidedText(opt.text, Qt::ElideMiddle, textRect.width());
    painter->drawText(textRect, Qt::TextSingleLine | static_cast<int>(opt.displayAlignment), text);

    if (opt.state & DStyle::State_Enabled) {
        QVariant iconVar = index.data(Qt::DecorationRole);
        if (opt.state & DStyle::State_MouseOver) {
            if (iconVar.isValid()) {
                QIcon icon = iconVar.value<QIcon>();
                QRect iconRect = iconLocationRect(rect, QSize(22, 22));
                icon.paint(painter, iconRect, Qt::AlignCenter);
            }
        }
    }

    painter->restore();
}

QSize HoverDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid())
        return DStyledItemDelegate::sizeHint(option, index);

    QSize size = DStyledItemDelegate::sizeHint(option, index);
    DListView *view = qobject_cast<DListView*>(parent());

    return QSize(view->viewport()->width(), size.height());
}

QRect HoverDelegate::iconLocationRect(QRect rect, QSize iconSize) const
{
    QRect iconRect = rect;

    iconRect.setX(rect.x() + rect.width() - iconSize.width() - 10);
    iconRect.setY(rect.y() + (iconRect.height() - iconSize.height()) / 2);
    iconRect.setHeight(iconSize.height());
    iconRect.setWidth(iconSize.width());

    return iconRect;
}

bool HoverDelegate::eventFilter(QObject *object, QEvent *event)
{
    switch (event->type()) {
    case QEvent::MouseButtonRelease: {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        DListView *view = qobject_cast<DListView*>(parent());
        const QModelIndex &index = view->indexAt(mouseEvent->pos());
        QRect rect = view->visualRect(index);
        rect.setWidth(view->viewport()->width());
        QRect decorationRect = iconLocationRect(rect, QSize(22, 22));

        if ((mouseEvent->button() == Qt::LeftButton) && decorationRect.contains(mouseEvent->pos())) {
            emit stateChanged(index);
            event->accept();
            return true;
        }

        break;
    }
    default:
        break;
    }

    return DStyledItemDelegate::eventFilter(object, event);
}
