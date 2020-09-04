#include "delegate.h"

#include <DStyle>

#include <QPainter>
#include <QDebug>

DWIDGET_USE_NAMESPACE

Delegate::Delegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void Delegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    painter->setRenderHints(painter->renderHints()
                            | QPainter::Antialiasing
                            | QPainter::SmoothPixmapTransform);

    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);
    auto style = opt.widget->style();

    int borderWidth = style->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderWidth),
                                         &opt, nullptr);
    int borderSpacing = style->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderSpacing),
                                           &opt, nullptr);
    const QMargins margins(borderWidth + borderSpacing, borderWidth + borderSpacing,
                           borderWidth + borderSpacing, borderWidth + borderSpacing);
    QPixmap pixmap = index.data(Qt::DecorationRole).value<QPixmap>();
    QPainterPath path;
    path.addEllipse(opt.rect.marginsRemoved(margins));
    painter->setClipPath(path);

    if(!pixmap.isNull()){
        painter->drawPixmap(opt.rect.marginsRemoved(margins),pixmap);
        painter->setClipping(false);
    } else {
        qreal tw = opt.rect.width() / 3.0;
        qreal th = opt.rect.height() / 3.0;

        //绘制背景
        DStyleHelper dh(style);
        //QRectF rect(tw + opt.rect.x(), th + opt.rect.y(), tw, th);
        //rect.moveCenter(QRect(opt.rect).center());
        painter->setPen(Qt::NoPen);
        painter->setBrush(dh.getColor(&opt, QPalette::Button));
        painter->drawEllipse(opt.rect.marginsRemoved(margins));

        //画+号
        qreal x1 = opt.rect.x() + tw ;
        qreal y1 = opt.rect.y() + opt.rect.height() / 2.0 - 0.5;
        qreal x2 = opt.rect.x() + opt.rect.width() / 2.0 - 0.5;
        qreal y2 = opt.rect.y() + th;
        painter->setBrush(dh.getColor(&opt, QPalette::Text));
        painter->drawRect(QRectF(x1, y1, tw, 1.0));
        painter->drawRect(QRectF(x2, y2, 1.0, th));
    }

    //index.data(Qt::CheckStateRole) == Qt::Checked  (opt.state & QStyle::State_Selected)
    //opt.state.testFlag(QStyle::State_Selected)
    if ((opt.state & QStyle::State_Selected) && !pixmap.isNull()) {
        painter->setPen(QPen(opt.palette.highlight(), borderWidth));
        painter->setBrush(Qt::NoBrush);
        painter->drawEllipse(opt.rect.adjusted(1, 1, -1, -1));

        //在中间绘制选中小图标
        int radius = 8;
        int cx = opt.rect.marginsRemoved(margins).center().x();
        int cy = opt.rect.marginsRemoved(margins).center().y();
        QRect crect(QPoint(cx - radius, cy - radius), QPoint(cx + radius, cy + radius));
        opt.rect = crect;
        opt.state |= QStyle::State_On;
        style->drawPrimitive(DStyle::PE_IndicatorItemViewItemCheck, &opt, painter, nullptr);
    }
}

QSize Delegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)

    return index.data(Qt::SizeHintRole).toSize();
}

StyledDelegate::StyledDelegate(QObject *parent) : QStyledItemDelegate(parent)
{

}

void StyledDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!index.isValid()) {
        QStyledItemDelegate::paint(painter, option, index);
        return;
    }

    painter->setRenderHints(painter->renderHints()
                            | QPainter::Antialiasing
                            | QPainter::SmoothPixmapTransform);

    QStyleOptionViewItem opt(option);
    initStyleOption(&opt, index);
    auto style = opt.widget->style();

    int borderWidth = style->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderWidth),
                                         &opt, nullptr);
    int borderSpacing = style->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderSpacing),
                                           &opt, nullptr);
    const QMargins margins(borderWidth + borderSpacing, borderWidth + borderSpacing,
                           borderWidth + borderSpacing, borderWidth + borderSpacing);

    int width = qMin(opt.rect.width(),opt.rect.height())/4;
    const QMargins margin(width, width, width, width);

    QIcon icon = index.data(Qt::DecorationRole).value<QIcon>();

    QBrush m_brush = opt.palette.brush(DPalette::ToolTipBase);

    if (opt.state & DStyle::State_Enabled) {
        if (opt.state & DStyle::State_MouseOver) {
            m_brush = opt.palette.brush(DPalette::Button);
        }
    }

    QPainterPath path;
    path.addRoundedRect(opt.rect, radius, radius);
    painter->setClipPath(path);
    painter->fillPath(path, m_brush);

    if(!icon.isNull()){
        icon.paint(painter,opt.rect.marginsRemoved(margin),Qt::AlignCenter);
    }

    QRect textRect = opt.rect;
    textRect.setY(opt.rect.y() + opt.rect.height()*5/6);
    painter->drawText(textRect, Qt::TextSingleLine | Qt::AlignHCenter, opt.text);
}

QSize StyledDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option)

    return index.data(Qt::SizeHintRole).toSize();
}
