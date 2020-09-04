#ifndef PERSONALIZATIONWIDGET_H
#define PERSONALIZATIONWIDGET_H

#include "widgets/iwindow.h"
#include <DListView>
#include <QStackedWidget>

DWIDGET_USE_NAMESPACE

enum ListItem{
    ConmmonItem,
    IconItem,
    CursorItem,
    FontItem
};

class PersonalizationWidget : public IWindow
{
    Q_OBJECT
public:
    explicit PersonalizationWidget(QWidget *parent = nullptr);

protected:
    void initLeftWidget() Q_DECL_OVERRIDE;
    void initRigthWidget() Q_DECL_OVERRIDE;
    void initConnection() Q_DECL_OVERRIDE;

signals:

public slots:
    void onChanged(const QModelIndex &index);

private:
    DListView *listView = Q_NULLPTR;
    QStackedWidget *stackedWidget = Q_NULLPTR;
    QMap<int,QWidget *> listWidget;
};

#endif // PERSONALIZATIONWIDGET_H
