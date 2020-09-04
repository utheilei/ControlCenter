#include "iwindow.h"
#include <QHBoxLayout>
#include <DVerticalLine>

DWIDGET_USE_NAMESPACE

IWindow::IWindow(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *hLayout = new QHBoxLayout;
    setLayout(hLayout);

    DVerticalLine *line = new DVerticalLine(this);
    hLayout->addWidget(line);
}

void IWindow::init()
{
    initLeftWidget();
    initRigthWidget();
    initConnection();
}
