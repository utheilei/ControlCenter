#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <DFloatingButton>

DWIDGET_USE_NAMESPACE

class ListIconView;
class AvatarWidget;
class FullNameEdit;
class SettingsGroup;
class QVBoxLayout;
class UserWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UserWidget(QWidget *parent = nullptr);
    ~UserWidget() Q_DECL_OVERRIDE;

    void initWidget(QVBoxLayout *layout);

protected:
    //bool eventFilter(QObject *target, QEvent *event) Q_DECL_OVERRIDE;

signals:
    //void loseFocus();

public slots:
    void showAccoutView();
    void setUserPixmap(QString &iconPath);

private:
    SettingsGroup *settingsGroup = Q_NULLPTR;
    FullNameEdit *fullNameEdit = Q_NULLPTR;
    AvatarWidget *btn = Q_NULLPTR;
    ListIconView *accoutView = Q_NULLPTR;
};

#endif // USERWIDGET_H
