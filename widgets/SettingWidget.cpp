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

#include "SettingWidget.h"

#include <QVBoxLayout>
#include <QEvent>

constexpr int radius = 8;

SettingWidget::SettingWidget(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
    m_contentWidget = new QFrame(this);
    m_layout = new QVBoxLayout();
    m_layout->setMargin(0);
    m_layout->setSpacing(0);
    m_contentWidget->setLayout(m_layout);

    // 矩形圆角
    m_clipEffectWidget = new DGraphicsClipEffect(m_contentWidget);
    m_contentWidget->installEventFilter(this);
    m_contentWidget->setGraphicsEffect(m_clipEffectWidget);

    mainLayout->addWidget(m_contentWidget);
    m_contentWidget->setAttribute(Qt::WA_TranslucentBackground);
}

SettingWidget::~SettingWidget()
{

}

void SettingWidget::setWidget(QWidget *widget)
{
    m_widget = widget;
    m_layout->addWidget(widget);
}

QWidget *SettingWidget::contentWidget() const
{
    return m_widget;
}

bool SettingWidget::eventFilter(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched)

    if (event->type() != QEvent::Move && event->type() != QEvent::Resize)
        return false;

    QRect rect = m_contentWidget->rect();

    QPainterPath path;
    path.addRoundedRect(rect, radius, radius);
    m_clipEffectWidget->setClipPath(path);

    return false;
}
