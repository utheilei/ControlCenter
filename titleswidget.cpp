#include "titleswidget.h"
#include "delegate.h"

#include <QHBoxLayout>

TitlesWidget::TitlesWidget(QWidget *parent)
    : DListView(parent)
    , m_model(new QStandardItemModel(this))
    , m_itemDelegate(new StyledDelegate(this))
{
    init();
    initItems();
}

void TitlesWidget::init()
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setViewMode(ViewMode::IconMode);
    setDragDropMode(QAbstractItemView::NoDragDrop);
    setDragEnabled(false);
    setSpacing(20);
    setResizeMode(DListView::Adjust);
    setFrameShape(QFrame::NoFrame);
    setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setEditTriggers(QAbstractItemView::NoEditTriggers);

    setItemDelegate(m_itemDelegate);
    setModel(m_model);
}

void TitlesWidget::initItems()
{

    const QStringList textList = {
        tr("account"),tr("cloudsync"),tr("display"),tr("defapp"),tr("personalization"),tr("network"),
        tr("sound"),tr("datetime"),tr("power"),tr("mouse"),tr("keyboard"),tr("unionid"),tr("update"),
        tr("systeminfo"),tr("commoninfo")
    };

    const QList<QString> iconList = {
        "dcc_nav_accounts","dcc_nav_cloudsync","dcc_nav_display","dcc_nav_defapp",
        "dcc_nav_personalization","dcc_nav_network","dcc_nav_sound","dcc_nav_datetime",
        "dcc_nav_power","dcc_nav_mouse","dcc_nav_keyboard","dcc_nav_unionid",
        "dcc_nav_update","dcc_nav_systeminfo","dcc_nav_commoninfo"
    };

    for (int i=0; i < textList.size(); i++) {
        addItem(QIcon::fromTheme(iconList[i]), textList[i]);
    }
}

void TitlesWidget::addItem(const QIcon &icon, const QString &text)
{
    QStandardItem *item = new QStandardItem();
    item->setText(text);
    item->setData(QVariant::fromValue(icon), Qt::DecorationRole);
    item->setData(m_size, Qt::SizeHintRole);
    m_model->appendRow(item);
}
