#ifndef HOVERDELEGATE_H
#define HOVERDELEGATE_H

#include <DStyledItemDelegate>

#include <QEvent>

DWIDGET_USE_NAMESPACE

class HoverDelegate : public DStyledItemDelegate
{
    Q_OBJECT
public:
    explicit HoverDelegate(QAbstractItemView *parent);

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    bool eventFilter(QObject *object, QEvent *event) Q_DECL_OVERRIDE;

private:
    QRect iconLocationRect(QRect rect, QSize iconSize) const;

Q_SIGNALS:
    void stateChanged(const QModelIndex &index);

private:
    int m_margins = 10;
    int m_checkWidth = 15;
};

#endif // HOVERDELEGATE_H
