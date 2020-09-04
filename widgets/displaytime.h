#ifndef DISPLAYTIME_H
#define DISPLAYTIME_H

#include "settingsitem.h"

#include <DLabel>

DWIDGET_USE_NAMESPACE

class DisplayTime : public SettingsItem
{
    Q_OBJECT
public:
    explicit DisplayTime(QWidget *parent = nullptr);

    void setDisplayFormat(bool displayFormat);

signals:

public slots:
    void changeTime();

private:
    DLabel *timeLabel = Q_NULLPTR;
    DLabel *label = Q_NULLPTR;
    DLabel *dateLabel = Q_NULLPTR;
    DLabel *weekLabel = Q_NULLPTR;
    bool m_displayFormat = false;
};

#endif // DISPLAYTIME_H
