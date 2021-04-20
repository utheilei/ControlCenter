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

#include "commonstylewidget.h"

#include <DApplicationHelper>

#include <QPainter>

DWIDGET_USE_NAMESPACE

constexpr int radius = 8;

CommonStyleWidget::CommonStyleWidget(BackgroundType type, QWidget *parent) : QWidget(parent)
{
    m_type = type;
}

void CommonStyleWidget::setBackgroundType(CommonStyleWidget::BackgroundType type)
{
    m_type = type;
    update();
}

CommonStyleWidget::BackgroundType CommonStyleWidget::currentBackgroundType()
{
    return m_type;
}

void CommonStyleWidget::paintEvent(QPaintEvent * event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿

    painter.setClipping(true);
    QPainterPath canDrawingPathArea;
    canDrawingPathArea.addRoundedRect(rect(), radius, radius);
    canDrawingPathArea.setFillRule(Qt::WindingFill); // 多块区域组合填充模式

    switch (m_type)
    {
    case LeftTop:// 左上角圆角
    {
        canDrawingPathArea.addRect(0, height() - radius, radius, radius); // 填充左下角
        canDrawingPathArea.addRect(width() - radius, 0, radius, radius); // 填充右上角
        canDrawingPathArea.addRect(width() - radius, height() - radius, radius, radius);// 填充右下角
        break;
    }
    case RightTop: // 右上角圆角
    {
        canDrawingPathArea.addRect(0, height() - radius, radius, radius); // 填充左下角
        canDrawingPathArea.addRect(0, 0, radius, radius); // 填充左上角
        canDrawingPathArea.addRect(width() - radius, height() - radius, radius, radius);// 填充右下角
        break;
    }
    case LeftBottom:// 左下角圆角
    {
        canDrawingPathArea.addRect(width() - radius, 0, radius, radius); // 填充右上角
        canDrawingPathArea.addRect(width() - radius, height() - radius, radius, radius);// 填充右下角
        canDrawingPathArea.addRect(0, 0, radius, radius); // 填充左上角
        break;
    }
    case RightBottom: // 右下角圆角
    {
        canDrawingPathArea.addRect(0, height() - radius, radius, radius); // 填充左下角
        canDrawingPathArea.addRect(width() - radius, 0, radius, radius); // 填充右上角
        canDrawingPathArea.addRect(0, 0, radius, radius); // 填充左上角
        break;
    }
    case Top:         // 上两个圆角
    {
        canDrawingPathArea.addRect(0, height() - radius, radius, radius); // 填充左下角
        canDrawingPathArea.addRect(width() - radius, height() - radius, radius, radius);// 填充右下角
        break;
    }
    case Bottom:     // 下两个圆角
    {
        canDrawingPathArea.addRect(width() - radius, 0, radius, radius); // 填充右上角
        canDrawingPathArea.addRect(0, 0, radius, radius); // 填充左上角
        break;
    }
    case Left:  // 左两个圆角
    {
        canDrawingPathArea.addRect(width() - radius, 0, radius, radius); // 填充右上角
        canDrawingPathArea.addRect(width() - radius, height() - radius, radius, radius);// 填充右下角
        break;
    }
    case Right:      // 右两个圆角
    {
        canDrawingPathArea.addRect(0, height() - radius, radius, radius); // 填充左下角
        canDrawingPathArea.addRect(0, 0, radius, radius); // 填充左上角
        break;
    }
    case All:          // 四个角圆角
    {
        break;
    }
    default:
        break;
    }
    painter.setClipPath(canDrawingPathArea);

    DApplicationHelper *dAppHelper = DApplicationHelper::instance();
    DPalette palette = dAppHelper->applicationPalette();
    QBrush brush = palette.brush(DPalette::ItemBackground);
    painter.setPen(Qt::NoPen);
    painter.setBrush(brush);
    painter.drawRect(rect());
}
