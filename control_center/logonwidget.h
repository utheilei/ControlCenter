#ifndef LOGONWIDGET_H
#define LOGONWIDGET_H

#include <DWidget>
#include <DLineEdit>

DWIDGET_USE_NAMESPACE

class LogonWidget : public DWidget
{
    Q_OBJECT
public:
    explicit LogonWidget(QWidget *parent = nullptr);

signals:

public slots:

private:
    DLineEdit *m_edit;
    DLineEdit *m_edit1;
};

#endif // LOGONWIDGET_H
