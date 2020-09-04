#ifndef ROUNDCOLORVIEW_H
#define ROUNDCOLORVIEW_H

#include <QWidget>

class RoundColorWidget;
class RoundColorView : public QWidget
{
    Q_OBJECT
public:
    explicit RoundColorView(QWidget *parent = nullptr);

    QColor currentColor();

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void colorChange(QColor color);

public slots:
    void onChanged();

private:
    QList<RoundColorWidget *> m_activeColorsList;
    RoundColorWidget *m_colorWidget = Q_NULLPTR;
};

#endif // ROUNDCOLORVIEW_H
