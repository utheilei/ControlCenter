#ifndef CHECKERBOARD_H
#define CHECKERBOARD_H

#include <QWidget>

class CheckerBoard : public QWidget
{
    Q_OBJECT
public:
    explicit CheckerBoard(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

private:
    int m_chessSize = 60;
};

#endif // CHECKERBOARD_H
