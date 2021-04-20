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

#ifndef ARROWCIRCLEBUTTON_H
#define ARROWCIRCLEBUTTON_H

#include <QWidget>

#define PIX_SIZE 60

class ArrowCircleButton : public QWidget
{
    Q_OBJECT

public:
    explicit ArrowCircleButton(const QPixmap &pixmap, QWidget *parent = Q_NULLPTR);

    void setPixmap(const QPixmap &pixmap);

    void setSelected(bool selected);

    void setArrowed(bool arrowed);

    inline bool arrowed() const { return m_arrowed; }

Q_SIGNALS:
    void clicked();

protected:
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
    void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;
    void enterEvent(QEvent *e) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *e) Q_DECL_OVERRIDE;

private:
    bool m_hover = false;
    bool m_selected = false;
    bool m_arrowed = false;

    QPixmap m_pixmap;
};

#endif // ARROWCIRCLEBUTTON_H
