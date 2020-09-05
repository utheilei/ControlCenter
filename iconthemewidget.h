#ifndef ICONTHEMEWIDGET_H
#define ICONTHEMEWIDGET_H

#include "listwidget.h"

class IconThemeWidget : public ListWidget
{
    Q_OBJECT
public:
    explicit IconThemeWidget(QWidget *parent = nullptr);

    void addIconItem(QString text, QWidget *widget);

    void init() Q_DECL_OVERRIDE;

signals:

public slots:
    void checkItem(const QModelIndex &index);
};

#endif // ICONTHEMEWIDGET_H
