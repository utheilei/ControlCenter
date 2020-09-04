#ifndef COMMONWIDGET_H
#define COMMONWIDGET_H

#include <QWidget>

class SettingsItem;
class CommonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CommonWidget(QWidget *parent = nullptr);

    void initAutoItem();

    void initTransparencyItem();

    void initMinItem();

signals:

public slots:

private:
    SettingsItem *autoItem = Q_NULLPTR;
    SettingsItem *transparencyItem = Q_NULLPTR;
    SettingsItem *minItem = Q_NULLPTR;
};

#endif // COMMONWIDGET_H
