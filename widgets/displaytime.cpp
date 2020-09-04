#include "displaytime.h"

#include <QBoxLayout>
#include <QLCDNumber>
#include <QTimer>
#include <QDateTime>
#include <DFontSizeManager>

DisplayTime::DisplayTime(QWidget *parent) : SettingsItem(parent)
{
    addBackground();

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(20,15,20,10);
    setLayout(layout);

    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->setAlignment(Qt::AlignHCenter);
    timeLabel = new DLabel(this);
    DFontSizeManager::instance()->bind(timeLabel, DFontSizeManager::T2, QFont::DemiBold);
    timeLabel->setText(QTime::currentTime().toString("HH:mm:ss"));

    QTimer *ptimer = new QTimer(this);
    connect(ptimer, &QTimer::timeout, this, &DisplayTime::changeTime);
    ptimer->start(1000);

    label = new DLabel(this);

    QTime time = QTime::currentTime();
    QString text = (time.hour() > 12) ? tr("afternoon") : tr("morning");
    label->setText(text);

    hlayout->addWidget(timeLabel);
    hlayout->addWidget(label);

    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->setAlignment(Qt::AlignHCenter);
    dateLabel = new DLabel(this);
    dateLabel->setText(QDate::currentDate().toString("yyyy-MM-dd"));
    weekLabel = new DLabel(this);
    weekLabel->setText(QDateTime::currentDateTime().toString("ddd"));
    hLayout->addWidget(dateLabel);
    hLayout->addSpacing(20);
    hLayout->addWidget(weekLabel);

    layout->addLayout(hlayout);
    layout->addLayout(hLayout);

}

void DisplayTime::setDisplayFormat(bool displayFormat)
{
    if (m_displayFormat != displayFormat) {
        m_displayFormat = displayFormat;
        changeTime();
    }
}

void DisplayTime::changeTime()
{
    QTime dateTime;
    QString text = "";
    if (m_displayFormat) {
        dateTime = QTime::currentTime();
        if (label->isVisible())
            label->setVisible(false);
    } else {
        if (!label->isVisible())
            label->setVisible(true);

        QTime time = QTime::currentTime();
        if (time.hour() > 12) {
            time = time.addSecs(-12*60*60);
            text = tr("afternoon");
        } else {
            text = tr("morning");
        }
        dateTime = time;
        label->setText(text);
    }

    timeLabel->setText(dateTime.toString("HH:mm:ss"));
}
