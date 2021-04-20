#include "displaywidget.h"
#include "widgets/cscrolltext.h"

#include <QPushButton>
#include <QVBoxLayout>

DisplayWidget::DisplayWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vLayout = new QVBoxLayout;
    setLayout(vLayout);
    CScrollText *scrolltext = new CScrollText(this);
    scrolltext->setFixedSize(400, 80);
    scrolltext->setFont(QFont("楷体",15,QFont::Bold));
    scrolltext->setText("https://github.com/utheilei！");
    scrolltext->move(50,50);

    CScrollText *scrollText = new CScrollText(this);
    scrollText->setFixedSize(400, 80);
    scrollText->setFont(QFont("隶书",15,QFont::Bold));
    scrollText->setText("这是一段很长的文字，目的就是为了让它超过范围！");
    scrollText->move(50,150);
    scrollText->startTimer(30);

    QPushButton *button = new QPushButton(this);
    button->setFixedSize(200, 30);
    button->setText("start");

    connect(button, &QPushButton::clicked, [=](){
        scrolltext->startTimer(20);
    });

    vLayout->addWidget(scrolltext, 0, Qt::AlignCenter);
    vLayout->addWidget(scrollText, 0, Qt::AlignCenter);
    vLayout->addWidget(button, 0, Qt::AlignCenter);
}
