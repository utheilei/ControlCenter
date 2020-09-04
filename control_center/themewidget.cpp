#include "themewidget.h"
#include "themepix.h"

#include <DFontSizeManager>
#include <QGridLayout>

const QList<QString> pixmaps = {
    ":/images/333.png",
    ":/images/111.png",
    ":/images/222.png"
};

const QList<QString> labels = {
    "浅色",
    "自动",
    "深色"
};

ThemeWidget::ThemeWidget(QWidget *parent) : QWidget(parent)
{
    QGridLayout *gLayout = new QGridLayout();
    setLayout(gLayout);

    for (int i=0;i<3;i++) {
        ThemePix *theme = new ThemePix(QPixmap(pixmaps.at(i)),this);
        DLabel *label = new DLabel(labels[i],this);
        gLayout->addWidget(theme, 0, i);
        gLayout->addWidget(label, 1, i, Qt::AlignHCenter);
        connect(theme,&ThemePix::clicked,this,&ThemeWidget::onChanged);
        m_themePixList.append(theme);
        m_map.insert(theme,label);
    }
}

QString ThemeWidget::currentTheme()
{
    if(Q_NULLPTR == m_themePix)
        return Q_NULLPTR;

    DLabel *label = m_map.value(m_themePix);

    return label->text();
}

void ThemeWidget::onChanged()
{
    ThemePix *widget = qobject_cast<ThemePix *>(sender());

    if(m_themePix == widget)
        return;

    m_themePix = widget;

    foreach (ThemePix *item, m_themePixList) {
        if(widget != item)
            item->setClicked(false);
    }

    emit themeChange(widget);
}
