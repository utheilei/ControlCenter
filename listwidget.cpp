#include "listwidget.h"

#include <QStandardItemModel>
#include <QStandardItem>
#include <DApplicationHelper>

ListWidget::ListWidget(QWidget *parent) : DListView(parent)
{
    setAutoFillBackground(true);
    DPalette pa = DApplicationHelper::instance()->palette(this);
    pa.setBrush(DPalette::ItemBackground, Qt::transparent);
    DApplicationHelper::instance()->setPalette(this, pa);

    setSelectionMode(QListView::SingleSelection);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

    m_itemModel = new QStandardItemModel;
    setModel(m_itemModel);
}

void ListWidget::init()
{
    const QList<QString> textList = {
        QObject::tr("account"),QObject::tr("cloudsync"),QObject::tr("display"),QObject::tr("defapp"),
        QObject::tr("personalization"),QObject::tr("network"),QObject::tr("sound"),QObject::tr("datetime"),
        QObject::tr("power"),QObject::tr("mouse"),QObject::tr("keyboard"),QObject::tr("unionid"),
        QObject::tr("update"),QObject::tr("systeminfo"),QObject::tr("commoninfo")
    };

    const QList<QString> iconList = {
        "dcc_nav_accounts","dcc_nav_cloudsync","dcc_nav_display","dcc_nav_defapp",
        "dcc_nav_personalization","dcc_nav_network","dcc_nav_sound","dcc_nav_datetime",
        "dcc_nav_power","dcc_nav_mouse","dcc_nav_keyboard","dcc_nav_unionid",
        "dcc_nav_update","dcc_nav_systeminfo","dcc_nav_commoninfo"
    };

    for (int i=0;i<textList.size();i++) {
        addItem(QIcon::fromTheme(iconList[i]),textList[i]);
    }
}

void ListWidget::addItem(const QIcon &icon, const QString &text)
{
    QStandardItem *account = new QStandardItem(icon,text);
    m_itemModel->appendRow(account);
}

QStandardItemModel *ListWidget::itemModel() const
{
    return m_itemModel;
}
