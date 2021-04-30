#include "checkerboard.h"

#include <QPainter>

CheckerBoard::CheckerBoard(QWidget *parent) : QWidget(parent)
{

}

void CheckerBoard::paintEvent(QPaintEvent *event)
{
    int delta = qMin(width(), height());
    int chessSize = delta / 11;
    m_chessSize = chessSize;
    QRect rect(0, 0, chessSize*10, chessSize*11);

    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(3);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    QPainterPath path;
    path.addRoundedRect(rect, 8, 8);
    painter.setClipPath(path);
    painter.setPen(pen);
    painter.fillPath(path, QBrush("#F0D28C"));

    for(int i = 0; i <= 9; i++) {
        painter.drawLine(QPoint(chessSize, chessSize + i*chessSize),
                         QPoint(chessSize + 8*chessSize, chessSize + i*chessSize));
    }

    for(int i = 0; i <= 8; i++) {
        if(i==0 || i==8) {
            painter.drawLine(QPoint(chessSize + i*chessSize, chessSize),
                             QPoint(chessSize + i*chessSize, chessSize + 9*chessSize));
        } else {
            painter.drawLine(QPoint(chessSize + i*chessSize, chessSize),
                             QPoint(chessSize + i*chessSize, chessSize + 4*chessSize));

            painter.drawLine(QPoint(chessSize + i*chessSize, chessSize + 5*chessSize),
                             QPoint(chessSize + i*chessSize, chessSize + 9*chessSize));
        }
    }

    painter.drawLine(QPoint(chessSize + 3*chessSize, chessSize),
                     QPoint(chessSize + 5*chessSize, chessSize + 2*chessSize));

    painter.drawLine(QPoint(chessSize + 3*chessSize, chessSize + 2*chessSize),
                     QPoint(chessSize + 5*chessSize, chessSize));

    painter.drawLine(QPoint(chessSize + 3*chessSize, chessSize + 7*chessSize),
                     QPoint(chessSize + 5*chessSize, chessSize + 9*chessSize));

    painter.drawLine(QPoint(chessSize + 3*chessSize, chessSize + 9*chessSize),
                     QPoint(chessSize + 5*chessSize, chessSize + 7*chessSize));
}
