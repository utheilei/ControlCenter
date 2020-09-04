/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
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

#ifndef AVATARWIDGET_H
#define AVATARWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <qevent.h>

#define PIX_SIZE    60

class AvatarWidget : public QLabel
{
    Q_OBJECT

public:
    explicit AvatarWidget(QPixmap pixmap, QWidget *parent = 0);

    void setPixmap(QPixmap pixmap);

    void setSelected(const bool selected = true);

    void setArrowed(const bool arrowed = true);
    inline bool arrowed() const { return m_arrowed; }
Q_SIGNALS:
    void clicked(const QString &iconPath) const;
    void clicked();
    void requestDelete(const QString &iconPath) const;

protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent *e);
    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    //void resizeEvent(QResizeEvent *event);

private:
    bool m_hover;
    bool m_deleable;
    bool m_selected;
    bool m_arrowed;

    QPixmap m_avatar;
    QString m_avatarPath;
};

#endif // AVATARWIDGET_H
