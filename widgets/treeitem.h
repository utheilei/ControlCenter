#ifndef TREEITEM_H
#define TREEITEM_H

#include <QIcon>
#include <QList>
#include <QVariant>
#include <QVector>

class TreeItem
{
public:
    explicit TreeItem(const QVector<QVariant> &data, TreeItem *parent = 0);
    ~TreeItem();

    TreeItem *child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    TreeItem *parent() const;
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant &value);

    void appendChild(TreeItem *item);
    void insertChild(int position, TreeItem *item);

    inline QIcon icon() const {
        return m_icon;
    }

    void setIcon(const QIcon &icon);

    int depth() const;

private:
    QList<TreeItem*> childItems;
    QVector<QVariant> itemData;
    TreeItem *parentItem;
    QIcon m_icon = QIcon();
};

#endif // TREEITEM_H
