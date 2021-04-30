#ifndef CHESSMAN_H
#define CHESSMAN_H

#include <QWidget>

// 棋子类型
typedef enum ChessType {
    JIANG,
    SHI,
    XIANG,
    MA,
    CHE,
    PAO,
    BING,
    None
} ChessType;

struct Piece {
    ChessType type = ChessType::None;
    bool isRed = true;
    int row = 0;
    int column = 0;
};

class ChessMan : public QWidget
{
    Q_OBJECT
public:
    explicit ChessMan(Piece chess, QWidget *parent = nullptr);

    QString chessName();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

private:
    Piece m_chess;
};

#endif // CHESSMAN_H
