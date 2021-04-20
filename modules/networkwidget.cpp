#include "networkwidget.h"

#include "widgets/waterprogressbar.h"
#include "widgets/gaugespeed.h"

#include <QHBoxLayout>
#include <QSlider>

NetworkWidget::NetworkWidget(QWidget *parent) : IWindow(parent)
{
    init();

    QHBoxLayout *hLayout = static_cast<QHBoxLayout *>(this->layout());
    hLayout->setContentsMargins(20, 10, 20, 10);
    hLayout->setSpacing(10);
    hLayout->insertWidget(0, m_leftWidget, 1);
    hLayout->addWidget(m_gauge, 1);
}

void NetworkWidget::initLeftWidget()
{
    m_leftWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    m_leftWidget->setLayout(layout);

    m_slider = new QSlider(Qt::Horizontal,this);
    m_slider->setMinimum(0);
    m_slider->setMaximum(100);

    m_probar = new WaterProgressBar(this);
    m_probar->setValue(30);
    m_probar->setRadius(50);
    m_probar->setBgColor(QColor("#352FFD"));
    m_probar->setWaterColor(QColor("#01C4FF"));
    m_probar->start();

    layout->addWidget(m_probar);
    layout->addWidget(m_slider);
}

void NetworkWidget::initRigthWidget()
{
    m_gauge = new GaugeSpeed(this);
    m_gauge->setValue(60);
    m_gauge->setRadius(150);
}

void NetworkWidget::initConnection()
{
    connect(m_slider, &QSlider::valueChanged, [=](int value){
        m_probar->setValue(value);
        m_gauge->setValue(value);
    });
}
