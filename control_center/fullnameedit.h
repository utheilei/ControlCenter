#ifndef FULLNAMEEDIT_H
#define FULLNAMEEDIT_H

#include <QWidget>
#include <DImageButton>
#include <DLabel>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

class FullNameEdit : public QWidget
{
    Q_OBJECT
public:
    explicit FullNameEdit(QWidget *parent = nullptr);

protected:
    bool eventFilter(QObject *target, QEvent *event) Q_DECL_OVERRIDE;

signals:
    void nameChanged(QString &name);

public slots:
    void changeWidget();
    void loseFocus();

private:
    DImageButton *m_edit = Q_NULLPTR;
    DLabel *label = Q_NULLPTR;
    QLineEdit *lineEdit = Q_NULLPTR;
    QHBoxLayout *layout = Q_NULLPTR;
};

#endif // FULLNAMEEDIT_H
