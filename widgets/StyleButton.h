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

//鼠标hover灰色背景，以及点击后高亮

#ifndef STYLEBUTTON_H
#define STYLEBUTTON_H

#include <DPushButton>
#include <QEvent>

DWIDGET_USE_NAMESPACE

class StyleButton : public DPushButton
{
public:
    StyleButton(const QString text, QWidget *parent = Q_NULLPTR);

protected:
    void enterEvent(QEvent *e) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *e) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    bool m_isEnter = false;
};

#endif // STYLEBUTTON_H
