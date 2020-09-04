#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <DListView>

DWIDGET_USE_NAMESPACE

class ListWidget : public DListView
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = nullptr);

    void init();

    void addItem(const QIcon &icon, const QString &text);

signals:

public slots:

private:
    QStandardItemModel *itemModel = Q_NULLPTR;

};

#endif // LISTWIDGET_H
