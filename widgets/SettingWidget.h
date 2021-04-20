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

//通用的圆角窗口

#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <DGraphicsClipEffect>

#include <QFrame>

DWIDGET_USE_NAMESPACE

class QVBoxLayout;
class SettingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SettingWidget(QWidget *parent = nullptr);
    ~SettingWidget() Q_DECL_OVERRIDE;

    void setWidget(QWidget *widget);
    QWidget *contentWidget() const;

protected:
    bool eventFilter(QObject *watched, QEvent *event) Q_DECL_OVERRIDE;

private:
    DGraphicsClipEffect *m_clipEffectWidget;
    QFrame *m_contentWidget;
    QVBoxLayout *m_layout;
    QWidget *m_widget = Q_NULLPTR;
};
#endif // SETTINGWIDGET_H
