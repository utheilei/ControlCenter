#include "datetimewidget.h"
#include "widgets/clockwidget.h"
#include "widgets/displaytime.h"
#include "settingsitem.h"

#include <QHBoxLayout>
#include <DLabel>

DateTimeWidget::DateTimeWidget(QWidget *parent) : IWindow(parent)
{
    init();

    QHBoxLayout *hLayout = static_cast<QHBoxLayout *>(this->layout());
    hLayout->insertWidget(0, leftWidget, 1);
    hLayout->addWidget(rightWidget, 2);
}

void DateTimeWidget::initLeftWidget()
{
    leftWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    leftWidget->setLayout(layout);

    ClockWidget *clockWidget = new ClockWidget(this);
    clockWidget->setMinimumHeight(200);
    displayWidget = new DisplayTime(this);

    SettingsItem *item = new SettingsItem(this);
    item->addBackground();
    QHBoxLayout *hlayout = new QHBoxLayout;
    item->setLayout(hlayout);
    DLabel *label = new DLabel(tr("24 hour"),this);
    switchButton = new DSwitchButton(this);
    hlayout->addWidget(label);
    hlayout->addStretch();
    hlayout->addWidget(switchButton);

    layout->addWidget(clockWidget);
    layout->addWidget(displayWidget);
    layout->addWidget(item);
    layout->addStretch();
}

void DateTimeWidget::initRigthWidget()
{
    rightWidget = new QWidget(this);
}

void DateTimeWidget::initConnection()
{
    connect(switchButton, &DSwitchButton::clicked,displayWidget,&DisplayTime::setDisplayFormat);
}
