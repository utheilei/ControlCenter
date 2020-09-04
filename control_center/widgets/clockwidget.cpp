#include "clockwidget.h"

#include <QPainter>
#include <QTime>
#include <QtMath>

ClockWidget::ClockWidget(QWidget *parent) : QWidget(parent)
{
    m_time = new QTimer(this);

    connect(m_time,&QTimer::timeout,[=](){
        this->update();
    });

    m_time->start(1000);
}

ClockWidget::~ClockWidget()
{
    stopTime();

    if (m_time) {
        delete m_time;
        m_time = Q_NULLPTR;
    }
}

void ClockWidget::setRadius(int radius)
{
    if (m_radius != radius) {
        m_radius = radius;
        update();
    }
}

void ClockWidget::startTime()
{
    if (!m_time->isActive())
        m_time->start(1000);
}

void ClockWidget::stopTime()
{
    if (m_time->isActive())
        m_time->stop();
}

void ClockWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPointF pos = QPointF(width() / 2.0, height() / 2.0);
    painter.translate(pos);

    drawClockDial(&painter);
    drawPointer(&painter);
}

void ClockWidget::drawClockDial(QPainter *painter)
{
    QPixmap pixmap;

    QDateTime datetime(QDateTime::currentDateTime());
    const QTime time(datetime.time());

    bool nightMode = !(time.hour() >= 6  && time.hour() < 18);

    if (nightMode) {
        pixmap = QPixmap(":/images/dcc_clock_black.svg");
    } else {
        pixmap = QPixmap(":/images/dcc_clock_white.svg");
    }

    painter->save();
    painter->drawPixmap(QPoint(-pixmap.width()/2,-pixmap.height()/2),pixmap);
    painter->restore();
}

void ClockWidget::drawPointer(QPainter *painter)
{
    QTime time = QTime::currentTime();
    int hour = time.hour();
    int minute = time.minute();
    int second = time.second();
    if (hour > 12)
        hour = hour - 12;
    QPixmap hpix = QPixmap(":/images/dcc_noun_hour.svg");
    QPixmap mpix = QPixmap(":/images/dcc_noun_minute.svg");
    QPixmap spix = QPixmap(":/images/dcc_noun_second.svg");

    painter->rotate(-90);

    painter->save();
    int angle = hour*30;
    int anglem = minute/2;
    painter->rotate(angle + anglem);
    painter->drawPixmap(QPoint(-hpix.width()/2,-hpix.height()/2),hpix);
    painter->restore();

    painter->save();
    int mAngle = minute*6;
    painter->rotate(mAngle);
    painter->drawPixmap(QPoint(-mpix.width()/2,-mpix.height()/2),mpix);
    painter->restore();

    painter->save();
    int sAngle = second*6;
    painter->rotate(sAngle);
    painter->drawPixmap(QPoint(-spix.width()/2,-spix.height()/2),spix);
    painter->restore();
}
