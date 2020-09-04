#ifndef LISTICONVIEW_H
#define LISTICONVIEW_H

#include <DListView>

DWIDGET_USE_NAMESPACE

class Delegate;
class QStandardItemModel;
class ListIconView : public DListView
{
    Q_OBJECT
public:
    enum ItemRole {
        AddAvatarRole = Dtk::UserRole + 1,
        SaveAvatarRole
    };

    enum AddItemMethod {
        AddItem,
        InsnsertItem
    };

    explicit ListIconView(QWidget *parent = nullptr);

    void init();

    void initItems();

    void addItem(QString &iconPath, AddItemMethod method);

signals:
    void currentIconPath(QString &iconPath);
    void currentIcon(QIcon &icon);

public slots:
    void onItemClicked(const QModelIndex &index);

private:
    QStandardItemModel *m_model = Q_NULLPTR;
    Delegate *m_itemDelegate = Q_NULLPTR;
    QSize m_size = QSize(70,70);
};

#endif // LISTICONVIEW_H
