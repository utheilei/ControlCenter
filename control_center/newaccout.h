#ifndef NEWACCOUT_H
#define NEWACCOUT_H

#include <QWidget>
#include <DPasswordEdit>
#include <DMessageBox>

DWIDGET_USE_NAMESPACE

class circleView;
class NewAccout : public QWidget
{
    Q_OBJECT
public:
    explicit NewAccout(QWidget *parent = nullptr);

private:
    void initAccoutWidget();

signals:
    void signalcancel();
    void signalNewaccout(const QPixmap &pix, const QString &accout,
                         const QString &name, const QString &password);

public slots:
    void slotCreatAccout();

private:
    QString m_accout;
    QString m_name;
    QString m_password;
    QString m_repeatpassword;
    DLineEdit *lineedit;
    DLineEdit *lineedit1;
    DPasswordEdit *edit;
    DPasswordEdit *edit1;
    DMessageBox *m_msg;
    circleView *circleWidget = Q_NULLPTR;
    QPixmap m_pixmap;
};

#endif // NEWACCOUT_H
