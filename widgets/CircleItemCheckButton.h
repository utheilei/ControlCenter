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

// 圆形图片按钮

#ifndef CIRCLEITEMCHECKBUTTON_H
#define CIRCLEITEMCHECKBUTTON_H

#include <QPushButton>

class CircleItemCheckButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CircleItemCheckButton(QWidget *parent = Q_NULLPTR);

    QPixmap pixmapToRound(const QPixmap &pixmap);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // CIRCLEITEMCHECKBUTTON_H
