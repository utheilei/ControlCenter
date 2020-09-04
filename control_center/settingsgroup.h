/*
 * Copyright (C) 2016 ~ 2018 Deepin Technology Co., Ltd.
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

#ifndef SETTINGSGROUP_H
#define SETTINGSGROUP_H

#include <DBackgroundGroup>

#include <QFrame>
#include <QTimer>

DWIDGET_USE_NAMESPACE

class QVBoxLayout;
class SettingsItem;

class SettingsGroup : public QFrame
{
    Q_OBJECT

public:
    enum BackgroundStyle {
        ItemBackground = 0,
        GroupBackground,
        NoneBackground
    };

    explicit SettingsGroup(QFrame *parent = nullptr, BackgroundStyle bgStyle = ItemBackground);
    ~SettingsGroup();

    SettingsItem *getItem(int index);
    void insertWidget(QWidget *widget);
    void insertItem(const int index, SettingsItem *item);
    void appendItem(SettingsItem *item);
    void appendItem(SettingsItem *item, BackgroundStyle bgStyle);
    void removeItem(SettingsItem *item);
    void moveItem(SettingsItem *item, const int index);
    void setSpacing(const int spaceing);

    int itemCount() const;
    void clear();
    QVBoxLayout *getLayout() const { return m_layout; }

private:
    BackgroundStyle m_bgStyle{ItemBackground};
    QVBoxLayout *m_layout;
    DBackgroundGroup *m_bggroup{nullptr};
};

#endif // SETTINGSGROUP_H
