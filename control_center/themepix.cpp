#include "themepix.h"

#include <QPainter>
#include <DStyle>
#include <QMouseEvent>

DWIDGET_USE_NAMESPACE

ThemePix::ThemePix(QPixmap pixmap, QWidget *parent) : QWidget(parent)
{
    setFixedSize(110,60);
    m_pix = pixmapToRound(pixmap);
}

QPixmap ThemePix::pixmapToRound(const QPixmap &src)
{
    if (src.isNull()) {
        return QPixmap();
    }

    auto pixmap = QPixmap(src);
    QSize size = pixmap.size();
    QPixmap mask(size);
    mask.fill(Qt::transparent);

    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addRoundedRect(0, 0, size.width(), size.height(),8,8);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, pixmap);

    return mask;
}

void ThemePix::setClicked(bool isClicked)
{
    if(m_isSelected == isClicked)
        return;

    m_isSelected = isClicked;

    update();
}

bool ThemePix::isClicked() const
{
    return m_isSelected;
}

void ThemePix::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        setClicked(true);
        Q_EMIT clicked();
    }
}

void ThemePix::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    int borderWidth = style()->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderWidth), nullptr, this);
    int borderSpacing = style()->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderSpacing), nullptr, this);
    int totalSpace = borderWidth + borderSpacing;
    QRect squareRect = rect();
    squareRect = squareRect.adjusted(totalSpace, totalSpace, -totalSpace, -totalSpace);

    painter.drawPixmap(squareRect, m_pix);

    if(m_isSelected){
        QStyleOption option;
        option.initFrom(this);
        style()->drawPrimitive(DStyle::PE_FrameFocusRect, &option, &painter, this);
    }
}
