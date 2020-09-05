#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <DListView>

DWIDGET_USE_NAMESPACE

class ListWidget : public DListView
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = nullptr);

    virtual void init();

    void addItem(const QIcon &icon, const QString &text);

    QStandardItemModel *itemModel() const;

signals:

public slots:

private:
    QStandardItemModel *m_itemModel = Q_NULLPTR;

};

#endif // LISTWIDGET_H
