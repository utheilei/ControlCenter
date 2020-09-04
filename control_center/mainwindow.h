#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DMainWindow>
#include <DTitlebar>
#include <QStackedWidget>

DWIDGET_USE_NAMESPACE

class TitlesWidget;
class ListWidget;
class MainWindow : public DMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

    void initContent();

    void initConnection();

signals:

public slots:
    void slotsetWidget(const QModelIndex &previous);
    void onChangeWidget(const QModelIndex &index);

private:
    DTitlebar *m_titlebar = Q_NULLPTR;
    QMap<QString,QWidget *> m_listWidget;
    QStackedWidget *m_stackedWidget = Q_NULLPTR;
    ListWidget *listwidget = Q_NULLPTR;
    QStackedWidget *m_mainWidget = Q_NULLPTR;
    TitlesWidget *m_titlesWidget = Q_NULLPTR;
    DIconButton *pDIconButtonLeft = Q_NULLPTR;
};

#endif // MAINWINDOW_H
