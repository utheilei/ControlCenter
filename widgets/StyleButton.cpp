/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
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

#include "StyleButton.h"

#include <DApplicationHelper>
#include <DStyle>
#include <QStylePainter>

constexpr int margins = 10;
constexpr int radius = 8;

StyleButton::StyleButton(const QString text, QWidget *parent)
    : DPushButton(text, parent)
{
    QFont f = font();
    f.setPixelSize(16);
    setFlat(true);
    setCheckable(true);
    setContentsMargins(margins, margins, contentsMargins().top(), contentsMargins().bottom());
}

void StyleButton::enterEvent(QEvent *e)
{
    m_isEnter = true;
    DPushButton::enterEvent(e);
}
void StyleButton::leaveEvent(QEvent *e)
{
    m_isEnter = false;
    DPushButton::leaveEvent(e);
}

void StyleButton::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    QRectF rect = this->rect();

    if (m_isEnter) {
        painter.setRenderHint(QPainter::Antialiasing);
        DPalette pa = DApplicationHelper::instance()->palette(this);
        painter.setBrush(QBrush(pa.color(DPalette::Button)));
        QColor penColor = pa.color(DPalette::Base);
        painter.setPen(QPen(penColor));
        QPainterPath painterPath;
        painterPath.addRoundedRect(rect, radius, radius);
        painter.drawPath(painterPath);
    }

    QStyleOptionButton btn;
    initStyleOption(&btn);
    QStylePainter stylePainter(this);
    stylePainter.drawControl(DStyle::CE_PushButton, btn);
}
