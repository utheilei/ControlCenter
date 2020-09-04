#ifndef LOGONWIDGET_H
#define LOGONWIDGET_H

#include <DDialog>

DWIDGET_USE_NAMESPACE

class QLineEdit;

class LogonWidget : public DDialog
{
    Q_OBJECT
public:
    explicit LogonWidget(QWidget *parent = nullptr);

signals:

public slots:
    void openUrl();

private:
    QLineEdit *m_edit;
    QLineEdit *m_edit1;
};

#endif // LOGONWIDGET_H
