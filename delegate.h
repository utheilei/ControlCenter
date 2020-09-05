#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>
#include <DStyledItemDelegate>

DWIDGET_USE_NAMESPACE

class Delegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Delegate(QObject *parent = nullptr);

    // painting
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    // set item size
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
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

private:
    int radius = 20;
};

class NormalDelegate : public DStyledItemDelegate
{
    Q_OBJECT
public:
    explicit NormalDelegate(QAbstractItemView *parent = nullptr);

protected:
    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const;
};

#endif // DELEGATE_H
