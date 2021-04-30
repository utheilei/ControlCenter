#include "chessman.h"

#include <QPainter>

ChessMan::ChessMan(Piece chess, QWidget *parent) : QWidget(parent)
{
    m_chess = chess;
}

QString ChessMan::chessName()
{
    QString name = "";
    switch (m_chess.type) {
    case ChessType::JIANG: {
        name = m_chess.isRed ? "帅" : "将";
        break;
    }
    case ChessType::SHI: {
        name = m_chess.isRed ? "仕" : "士";
        break;
    }
    case ChessType::XIANG: {
        name = m_chess.isRed ? "相" : "象";
        break;
    }
    case ChessType::MA: {
        name = "馬";
        break;
    }
    case ChessType::CHE: {
        name = "車";
        break;
    }
    case ChessType::PAO: {
        name = "炮";
        break;
    }
    case ChessType::BING: {
        name = m_chess.isRed ? "兵" : "卒";
        break;
    }
    default:
        break;
    }

    return name;
}

void ChessMan::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPen pen;
    QColor color = m_chess.isRed ? Qt::red : Qt::black;
    pen.setColor(color);
    pen.setWidth(1);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    QRect rect = this->rect();
    int delta = qMin(rect.width(), rect.height());
    QRect roundRect = QRect(rect.left(), rect.top(), delta, delta);
    QPainterPath path;
    path.addEllipse(roundRect);
    painter.setClipPath(path);
    painter.setPen(pen);
    painter.setBrush(QBrush("#D1AF6F"));
    painter.drawPath(path);

    QRect circleRect = roundRect.adjusted(4, 4, -4, -4);
    painter.drawEllipse(circleRect);

    painter.setFont(QFont("Microsoft YaHei", 18, QFont::DemiBold));
    painter.drawText(roundRect, Qt::TextSingleLine | Qt::AlignCenter, chessName());
}
