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

// 设置全名输入编辑框控件

#ifndef FULLNAMEEDIT_H
#define FULLNAMEEDIT_H

#include <DIconButton>
#include <DLabel>

DWIDGET_USE_NAMESPACE

class QHBoxLayout;

class FullNameEdit : public QWidget
{
    Q_OBJECT
public:
    explicit FullNameEdit(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *target, QEvent *event) Q_DECL_OVERRIDE;

signals:
    void nameChanged(QString &name);

public slots:
    void changeWidget();
    void loseFocus();

private:
    DIconButton *m_edit = Q_NULLPTR;
    DLabel *m_label = Q_NULLPTR;
    QLineEdit *m_lineEdit = Q_NULLPTR;
    QHBoxLayout *m_layout = Q_NULLPTR;
};

#endif // FULLNAMEEDIT_H
