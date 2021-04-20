#ifndef CSCROLLTEXT_H
#define CSCROLLTEXT_H

#include <QWidget>
#include <QPixmap>

class CScrollText : public QWidget
{
    Q_OBJECT
public:

    explicit CScrollText(QWidget *parent = nullptr);

    void setText(const QString& text);

    int  getTextWidth();

    int  getTextHeight();

    void paintBackground();

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);

private:
    QString m_text;
    int m_posX;
    QPixmap m_bgPixmap;
};

#endif // CSCROLLTEXT_H
