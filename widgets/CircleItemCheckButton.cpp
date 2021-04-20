/*
* Copyright (C) 2020 ~ 2025 Uniontech Software Technology Co.,Ltd.
*
* Author:     helei <helei@uniontech.com>
*
* Maintainer: helei <helei@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "CircleItemCheckButton.h"

#include <DApplicationHelper>
#include <DStyle>
#include <QPaintEvent>

DWIDGET_USE_NAMESPACE

constexpr int radius = 8;
constexpr int penWidth = 4;

CircleItemCheckButton::CircleItemCheckButton(QWidget *parent) : QPushButton(parent)
{
    setFlat(true);
    setCheckable(true);
}

QPixmap CircleItemCheckButton::pixmapToRound(const QPixmap &pixmap)
{
    if (pixmap.isNull()) {
        return QPixmap();
    }

    auto conversionPixmap = QPixmap(pixmap);
    QSize size = conversionPixmap.size();
    QPixmap mask(size);
    mask.fill(Qt::transparent);

    QPainter painter(&mask);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addEllipse(0, 0, size.width(), size.height());
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, conversionPixmap);

    return mask;
}

void CircleItemCheckButton::paintEvent(QPaintEvent *event)
{
    auto style = this->style();
    QStyleOptionButton option;
    initStyleOption(&option);

    QPainterPath painterPath;
    painterPath.addEllipse(QRect(0, 0, width(), height()));

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setClipPath(painterPath);

    DPalette palette = DApplicationHelper::instance()->palette(this);
    QColor color = palette.color(QPalette::Highlight);

    if (!icon().isNull()) {
        QPixmap pixmap = icon().pixmap(size());
        painter.drawPixmap(event->rect(), pixmapToRound(pixmap));

        if(isChecked()){
            QPen pen(Qt::transparent);
            pen.setWidth(penWidth);
            pen.setColor(color);
            painter.setBrush(Qt::NoBrush);
            painter.setPen(pen);
            painter.drawEllipse(rect());

            int cx = this->rect().center().x();
            int cy = this->rect().center().y();
            QRect crect(QPoint(cx - radius, cy - radius), QPoint(cx + radius, cy + radius));
            option.rect = crect;

            style->drawPrimitive(DStyle::PE_IndicatorItemViewItemCheck, &option, &painter, Q_NULLPTR);
        }
    } else {
        qreal tw = option.rect.width() / 3.0;
        qreal th = option.rect.height() / 3.0;
        painter.setPen(Qt::NoPen);
        painter.setBrush(palette.brush(DPalette::Button));
        if (option.state & QStyle::State_MouseOver)
            painter.setBrush(palette.brush(DPalette::PlaceholderText));
        painter.drawEllipse(option.rect);

        //画+号
        qreal x1 = option.rect.x() + tw ;
        qreal y1 = option.rect.y() + option.rect.height() / 2.0 - 0.5;
        qreal x2 = option.rect.x() + option.rect.width() / 2.0 - 0.5;
        qreal y2 = option.rect.y() + th;
        painter.setBrush(palette.brush(DPalette::Text));
        painter.drawRect(QRectF(x1, y1, tw, 1.0));
        painter.drawRect(QRectF(x2, y2, 1.0, th));
    }
}
