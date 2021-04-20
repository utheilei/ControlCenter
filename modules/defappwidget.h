#ifndef DEFAPPWIDGET_H
#define DEFAPPWIDGET_H

#include "widgets/iwindow.h"

#include <DListView>

DWIDGET_USE_NAMESPACE

class SettingWidget;
class HoverDelegate;

class DefAppWidget : public IWindow
{
    Q_OBJECT
public:
    explicit DefAppWidget(QWidget *parent = nullptr);

protected:
    void initLeftWidget() Q_DECL_OVERRIDE;
    void initRigthWidget() Q_DECL_OVERRIDE;
    void initConnection() Q_DECL_OVERRIDE;

signals:

public slots:

private:
    SettingWidget *m_leftWidget = Q_NULLPTR;
    SettingWidget *m_rightWidget = Q_NULLPTR;
    DListView *m_leftView = Q_NULLPTR;
    DListView *m_rightView = Q_NULLPTR;
    HoverDelegate *m_hoverDelegate = Q_NULLPTR;
};

#endif // DEFAPPWIDGET_H
