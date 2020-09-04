#ifndef DATETIMEWIDGET_H
#define DATETIMEWIDGET_H

#include "widgets/iwindow.h"
#include <DSwitchButton>

DWIDGET_USE_NAMESPACE

class DisplayTime;

class DateTimeWidget : public IWindow
{
    Q_OBJECT
public:
    explicit DateTimeWidget(QWidget *parent = nullptr);

protected:
    void initLeftWidget() Q_DECL_OVERRIDE;
    void initRigthWidget() Q_DECL_OVERRIDE;
    void initConnection() Q_DECL_OVERRIDE;

signals:

public slots:

private:
    QWidget *leftWidget = Q_NULLPTR;
    QWidget *rightWidget = Q_NULLPTR;
    DisplayTime * displayWidget = Q_NULLPTR;
    DSwitchButton *switchButton = Q_NULLPTR;
};

#endif // DATETIMEWIDGET_H
