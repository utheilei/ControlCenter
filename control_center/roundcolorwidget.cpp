/*
 * Copyright (C) 2017 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     LiLinling <lilinling_cm@deepin.com>
 *
 * Maintainer: LiLinling <lilinling_cm@deepin.com>
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
#include "roundcolorwidget.h"

#include <DStyle>

#include <QColor>
#include <QPainter>
#include <QMouseEvent>
#include <QApplication>
#include <QDebug>

DWIDGET_USE_NAMESPACE

RoundColorWidget::RoundColorWidget(const QColor &color, QWidget *parent)
    : QWidget(parent)
    , m_isSelected(false)
    , m_color(color)
{
}

bool RoundColorWidget::isSelected()
{
    return m_isSelected;
}

void RoundColorWidget::setSelected(bool selected)
{
    if (m_isSelected == selected)
        return;

    m_isSelected = selected;

    update();
}

QColor RoundColorWidget::roundColor()
{
    return m_color;
}

void RoundColorWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        setSelected(true);
        Q_EMIT clicked();
    }
}

void RoundColorWidget::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    return;
}

void RoundColorWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    int borderWidth = style()->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderWidth), nullptr, this);
    int borderSpacing = style()->pixelMetric(static_cast<QStyle::PixelMetric>(DStyle::PM_FocusBorderSpacing), nullptr, this);
    int totalSpace = borderWidth + borderSpacing;
    QRect squareRect = rect();
    int delta = qMin(squareRect.width(),squareRect.height());
    QRect roundRect = QRect(squareRect.left(),squareRect.top(),delta,delta);
    QRect r = roundRect.adjusted(6, 6, -6, -6);

    QPainterPath painterPath;
    painterPath.addEllipse(roundRect);
    painter.setClipPath(painterPath);

    QPainterPath path;
    path.addEllipse(r);
    painter.setPen(Qt::NoPen);
    painter.drawPath(path);
    painter.fillPath(path, QBrush(m_color));

    if (m_isSelected) {
        QPen pen(Qt::transparent);
        pen.setWidth(totalSpace);
        pen.setColor(m_color);
        painter.setPen(pen);
        painter.drawEllipse(roundRect);
    }
}
