#ifndef TREEVIEWDELEGATE_H
#define TREEVIEWDELEGATE_H

#include <QStyledItemDelegate>

class TreeViewDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit TreeViewDelegate(QObject *parent = nullptr);

    void paint(QPainter *painter,const QStyleOptionViewItem &option, const QModelIndex &index) const;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // TREEVIEWDELEGATE_H
