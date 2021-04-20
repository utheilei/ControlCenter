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

// 绘制任意角为圆角的窗口

#ifndef COMMONSTYLEWIDGET_H
#define COMMONSTYLEWIDGET_H

#include <QWidget>

class CommonStyleWidget : public QWidget
{
    Q_OBJECT
public:
    // 窗口类型
    typedef enum BackgroundType {
        LeftTop = 0,
        RightTop,
        LeftBottom,
        RightBottom,
        Top,
        Bottom,
        Left,
        Right,
        All
    } BackgroundType;

    explicit CommonStyleWidget(BackgroundType type = BackgroundType::All, QWidget *parent = nullptr);

    void setBackgroundType(BackgroundType type);

    BackgroundType currentBackgroundType();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    BackgroundType m_type = BackgroundType::All;
};

#endif // COMMONSTYLEWIDGET_H
