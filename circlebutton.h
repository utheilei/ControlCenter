#ifndef CIRCLEBUTTON_H
#define CIRCLEBUTTON_H

#include <QWidget>
#include <QFrame>
#include <QPaintEvent>
#include <QPainter>
#include <DStyle>

DWIDGET_USE_NAMESPACE

class CircleButton : public QFrame
{
    Q_OBJECT
public:
    explicit CircleButton(QPixmap pixmap,QWidget *parent = nullptr);
    CircleButton(DStyle::StandardPixmap st,QWidget *parent = nullptr);

    QPixmap PixmapToRound(QPixmap &src, int radius);

    QPixmap pixmapToRound(const QPixmap &src);

    QPixmap pixmap();

    void setClickState(bool isChecked);

    bool clickState();

protected:
    void paintEvent(QPaintEvent *) override;

signals:

public slots:

private:
    QPixmap m_pixmap;
    bool m_clicked = false;
    bool m_checked = false;
};

#endif // CIRCLEBUTTON_H
