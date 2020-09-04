#ifndef IWINDOW_H
#define IWINDOW_H

#include <QWidget>

class IWindow : public QWidget
{
    Q_OBJECT
public:
    explicit IWindow(QWidget *parent = nullptr);

    void init();

protected:
    virtual void initLeftWidget() = 0;
    virtual void initRigthWidget() = 0;
    virtual void initConnection() = 0;

signals:

public slots:
};

#endif // IWINDOW_H
