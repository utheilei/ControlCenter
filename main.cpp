#include <DApplication>
#include <DWidgetUtil>
#include "mainwindow.h"
#include "widgets/iconwidget.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.loadTranslator();
    a.setOrganizationName("deepin");
    a.setApplicationName(QObject::tr("control_center"));
    a.setApplicationVersion("3.0.0");
    a.setProductIcon(QIcon::fromTheme("controlcenter"));
    a.setProductName(QObject::tr("control_center"));
    a.setApplicationDescription(QObject::tr("This is a dtk template application."));

    MainWindow w;
    w.setMinimumSize(800, 640);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
