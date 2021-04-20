/*
* Copyright (C) 2019 ~ 2020 Uniontech Software Technology Co.,Ltd.
*
* Author:     waleon <wanglianga@uniontech.com>
*
* Maintainer: waleon <wanglianga@uniontech.com>
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

// 视图，用于显示表格数据

#ifndef TREE_VIEW_H
#define TREE_VIEW_H

#include <DTreeView>

class TreeViewPrivate;

DWIDGET_USE_NAMESPACE

class TreeView : public DTreeView
{
    Q_OBJECT

public:
    explicit TreeView(QWidget *parent = Q_NULLPTR);
    ~TreeView() Q_DECL_OVERRIDE;

    // 更新控件位置
    void updateContent();

protected:
    void keyPressEvent(QKeyEvent *event) Q_DECL_OVERRIDE;
    void drawBranches(QPainter *painter, const QRect &rect, const QModelIndex &index) const Q_DECL_OVERRIDE;

private:
    Q_DISABLE_COPY(TreeView)
    Q_DECLARE_PRIVATE(TreeView)

    TreeViewPrivate *d_ptr = Q_NULLPTR;
};

#endif // TREE_VIEW_H
