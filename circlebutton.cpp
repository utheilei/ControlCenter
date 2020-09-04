#include "circlebutton.h"
#include <QBitmap>
#include <QDebug>
#include <QStyleOption>

CircleButton::CircleButton(QPixmap pixmap,QWidget *parent) : QFrame(parent)
{
    setFixedSize(40, 40);
    m_pixmap = pixmap;
    //m_pixmap.scaled(this->width(),this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    //m_pixmap = pixmapToRound(m_pixmap);
    setFocusPolicy(Qt::StrongFocus);
}

CircleButton::CircleButton(DStyle::StandardPixmap st, QWidget *parent) : QFrame(parent)
{
    setFixedSize(40, 40);
    setFocusPolicy(Qt::StrongFocus);
    QIcon icon = DStyleHelper(style()).standardIcon(st, nullptr, this);
    m_pixmap = icon.pixmap(30,30);
}

QPixmap CircleButton::PixmapToRound(QPixmap &src, int radius)
{
    if (src.isNull()) {
        return QPixmap();
    }
    QSize size(2*radius, 2*radius);
    QBitmap mask(size);
    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.fillRect(0, 0, size.width(), size.height(), Qt::white);
    painter.setBrush(QColor(0, 0, 0));
    painter.drawRoundedRect(0, 0, size.width(), size.height(), 99, 99);
    QPixmap image = src.scaled(size);
    image.setMask(mask);
    return image;
}

QPixmap CircleButton::pixmapToRound(const QPixmap &src)
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
    path.addEllipse(0, 0, size.width(), size.height());
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, pixmap);

    return mask;
}

QPixmap CircleButton::pixmap()
{
    return m_pixmap;
}

void CircleButton::setClickState(bool isChecked)
{
    if(m_clicked == isChecked)
        return;

    m_clicked = isChecked;
    update();
}

bool CircleButton::clickState()
{
    return m_clicked;
}

void CircleButton::paintEvent(QPaintEvent *e)
{
    auto style = this->style();
    QStyleOptionFrame option;
    initStyleOption(&option);

    QPainterPath painterPath;
    painterPath.addEllipse(QRect(0, 0, width(), height()));

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setClipPath(painterPath);

    painter.drawPixmap(e->rect(), m_pixmap);

    QPalette pal(palette());
    QColor color =  pal.color(QPalette::Highlight);

    if(m_clicked){
        QPen pen(Qt::transparent);
        pen.setWidth(4);
        pen.setColor(color);
        painter.setPen(pen);
        painter.drawEllipse(rect());

        int radius = 8;
        int cx = this->rect().center().x();
        int cy = this->rect().center().y();
        QRect crect(QPoint(cx - radius, cy - radius), QPoint(cx + radius, cy + radius));
        option.rect = crect;
        option.state |= QStyle::State_On;

        style->drawPrimitive(DStyle::PE_IndicatorItemViewItemCheck, &option, &painter, nullptr);
    }
}
