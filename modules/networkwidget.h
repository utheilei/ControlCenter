#ifndef NETWORKWIDGET_H
#define NETWORKWIDGET_H

#include "widgets/iwindow.h"

class WaterProgressBar;
class GaugeSpeed;
class QSlider;

class NetworkWidget : public IWindow
{
    Q_OBJECT
public:
    explicit NetworkWidget(QWidget *parent = nullptr);

protected:
    void initLeftWidget() Q_DECL_OVERRIDE;
    void initRigthWidget() Q_DECL_OVERRIDE;
    void initConnection() Q_DECL_OVERRIDE;

signals:

public slots:

private:
    QWidget *m_leftWidget = Q_NULLPTR;
    WaterProgressBar *m_probar = Q_NULLPTR;
    GaugeSpeed *m_gauge = Q_NULLPTR;
    QSlider *m_slider = Q_NULLPTR;
};

#endif // NETWORKWIDGET_H
