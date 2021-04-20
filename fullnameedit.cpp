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

#include "fullnameedit.h"

#include <DApplication>

#include <QLineEdit>
#include <QHBoxLayout>
#include <QFocusEvent>

FullNameEdit::FullNameEdit(QWidget *parent) : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    m_layout = new QHBoxLayout;
    setLayout(m_layout);
    m_layout->setMargin(0);
    m_layout->setContentsMargins(0,0,0,0);

    m_edit = new DIconButton(this);
    m_edit->setFlat(true);
    DStyle *style = dynamic_cast<DStyle *>(DApplication::style());
    m_edit->setIcon(style->standardIcon(DStyle::SP_EditElement, Q_NULLPTR, Q_NULLPTR));

    m_label = new DLabel(tr("set full name"),this);
    m_label->setEnabled(false);
    m_lineEdit = new QLineEdit(this);
    m_lineEdit->hide();
    m_lineEdit->installEventFilter(this);
    m_lineEdit->setFocusPolicy(Qt::StrongFocus);

    m_layout->addStretch();
    m_layout->addWidget(m_label);
    m_layout->addWidget(m_edit);
    m_layout->addWidget(m_lineEdit);
    m_layout->addStretch();

    connect(m_edit,&DIconButton::clicked,this,&FullNameEdit::changeWidget);
    connect(m_lineEdit,&QLineEdit::returnPressed,this,&FullNameEdit::loseFocus);
}

bool FullNameEdit::eventFilter(QObject *target, QEvent *event)
{
    if (target == m_lineEdit)
    {
        if (event->type() == QEvent::FocusOut)
            loseFocus();
    }

    return QWidget::eventFilter(target, event);
}

void FullNameEdit::changeWidget()
{
    m_label->hide();
    m_edit->hide();
    m_layout->removeItem(m_layout->itemAt(0));
    m_layout->removeItem(m_layout->itemAt(m_layout->count()-1));
    m_lineEdit->show();
    m_lineEdit->setFocus();
}

void FullNameEdit::loseFocus()
{
    m_lineEdit->hide();
    m_label->show();
    m_edit->show();

    if (m_layout->count() < 5) {
        m_layout->insertStretch(0);
        m_layout->insertStretch(m_layout->count());
    }

    if(m_lineEdit->text().isEmpty()) {
        m_label->setText(tr("set full name"));
    } else {
        QString name = m_lineEdit->text();
        m_label->setText(name);
        emit nameChanged(name);
    }
}
