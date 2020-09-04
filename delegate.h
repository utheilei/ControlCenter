#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>
#include <dstyleditemdelegate.h>

class Delegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // set item size
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:
};

class StyledDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit StyledDelegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // set item size
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

signals:

public slots:

private:
    int radius = 20;
};

#endif // DELEGATE_H
