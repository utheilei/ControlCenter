#ifndef THEMEPIX_H
#define THEMEPIX_H

#include <QWidget>

class ThemePix : public QWidget
{
    Q_OBJECT
public:
    explicit ThemePix(QPixmap pixmap, QWidget *parent = nullptr);

    QPixmap pixmapToRound(const QPixmap &src);

    void setClicked(bool isClicked);

    bool isClicked() const;

protected:
    void mousePressEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent *event);

signals:
    void clicked();

public slots:

private:
    QPixmap m_pix;
    bool m_isSelected = false;
};

#endif // THEMEPIX_H
