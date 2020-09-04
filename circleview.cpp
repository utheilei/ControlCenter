#include "circleview.h"
#include "circlebutton.h"
#include <QFocusEvent>
#include <QDebug>

circleView::circleView(QWidget *parent) : QWidget(parent)
{
   init();
   setFocusPolicy(Qt::StrongFocus);
}

void circleView::init()
{
    this->setMinimumWidth(240);
    mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(10,0,0,0);
    this->setLayout(mainLayout);
}

void circleView::addWidget(QWidget *w)
{
    m_count++;
    int colum = this->width()/60;
    updateWidget(w,m_count,colum);
}

void circleView::mousePressEvent(QMouseEvent *event)
{
    QList<CircleButton *> list = this->findChildren<CircleButton *>();

    foreach(CircleButton *w,list){
        if(w->geometry().contains(event->pos())) {
            w->setClickState(true);
            emit currentWidget(w);
        } else {
            w->setClickState(false);
        }
    }
}

void circleView::resizeEvent(QResizeEvent *event)
{
    for(int i=mainLayout->count();i>0;i--){
        mainLayout->removeItem(mainLayout->itemAt(i-1));
    }

    m_count = 0;
    QList<CircleButton *> list = this->findChildren<CircleButton *>();

    for (int j =0;j<list.count();j++) {
        addWidget(list[j]);
    }

    QWidget::resizeEvent(event);
}

void circleView::updateWidget(QWidget *w, int count, int colum)
{
    int row = count/colum;
    int num = count % colum;

    if(count <= colum){
        if(mainLayout->count() == 0){
            QHBoxLayout *layout1 = new QHBoxLayout();
            layout1->setSpacing(20);
            layout1->setAlignment(Qt::AlignLeft);
            mainLayout->addLayout(layout1);
        }
        QLayout *layout = mainLayout->itemAt(0)->layout();
        if(layout)
            layout->addWidget(w);
    } else {
        if(mainLayout->count()-1 < row){
            if (num == 0){
                QLayout *layout = mainLayout->itemAt(row-1)->layout();
                if(layout)
                    layout->addWidget(w);
            } else {
                QHBoxLayout *layout1 = new QHBoxLayout();
                layout1->setSpacing(20);
                layout1->setAlignment(Qt::AlignLeft);
                mainLayout->addLayout(layout1);
                layout1->addWidget(w);
            }
        } else {
            QLayout *layout = mainLayout->itemAt(row)->layout();
            if(layout)
                layout->addWidget(w);
        }
    }
}
