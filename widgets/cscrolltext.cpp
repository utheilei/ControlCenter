#include "cscrolltext.h"

#include <QPainter>

CScrollText::CScrollText(QWidget *parent) : QWidget(parent)
{
    resize(300,50);
    m_bgPixmap = QPixmap(300,50);
    paintBackground();
    m_posX = 0;
}

void CScrollText::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::TextAntialiasing);

    painter.fillRect(rect(),Qt::black);
    painter.drawPixmap(rect(),m_bgPixmap);

    painter.setPen(QColor(200,34,13));
    painter.drawText(m_posX,(height() - getTextHeight())/2 + getTextHeight(), m_text);
}

void CScrollText::timerEvent(QTimerEvent *event)
{
    m_posX -= 1;

    if(m_posX < 0 && abs(m_posX) >= getTextWidth()){
        m_posX = this->width();
    }

    update();
}

void CScrollText::setText(const QString& text)
{
    m_text = text;
    update();
}

int CScrollText::getTextWidth()
{
    QFontMetrics fMetrics(font());
    return fMetrics.width(m_text);
}

int CScrollText::getTextHeight()
{
    QFontMetrics fMetrics(font());
    return fMetrics.height();
}

void CScrollText::paintBackground()
{
    QPainter painter(&m_bgPixmap);
    painter.fillRect(m_bgPixmap.rect(),Qt::black);
    painter.setPen(QColor(200,200,200,66));

    int xCount = width()/5;
    int yCount = height()/5;
    for(int i = 0; i < xCount; ++i)
    {
        for(int j = 0; j < yCount; ++j){
            painter.drawPoint(i*5,5*j);
        }
    }
}

