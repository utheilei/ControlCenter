#include "commonwidget.h"
#include "roundcolorview.h"
#include "themewidget.h"
#include "settingsitem.h"

#include <DFontSizeManager>
#include <DLabel>
#include <QVBoxLayout>
#include <DSwitchButton>
#include <DSlider>
#include <DComboBox>

DWIDGET_USE_NAMESPACE

CommonWidget::CommonWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    setLayout(mainLayout);
    mainLayout->addSpacing(10);

    DLabel *themeLabel = new DLabel(tr("主题"));
    DFontSizeManager::instance()->bind(themeLabel, DFontSizeManager::T5, QFont::DemiBold);
    mainLayout->addWidget(themeLabel, 0, Qt::AlignLeft);
    ThemeWidget *theme = new ThemeWidget(this);
    mainLayout->addWidget(theme);

    DLabel *roundColorLabel = new DLabel(tr("活动用色"));
    DFontSizeManager::instance()->bind(roundColorLabel, DFontSizeManager::T5, QFont::DemiBold);
    mainLayout->addWidget(roundColorLabel, 0, Qt::AlignLeft);
    RoundColorView *view = new RoundColorView(this);
    mainLayout->addWidget(view);
    mainLayout->addSpacing(20);

    initAutoItem();
    mainLayout->addWidget(autoItem);
    mainLayout->addSpacing(20);

    initTransparencyItem();
    mainLayout->addWidget(transparencyItem);
    mainLayout->addSpacing(20);

    initMinItem();
    mainLayout->addWidget(minItem);

    mainLayout->addStretch();
}

void CommonWidget::initAutoItem()
{
    autoItem = new SettingsItem(this);
    autoItem->addBackground();
    DLabel *autoLabel = new DLabel(tr("窗口特效"));
    QHBoxLayout *hLayout = new QHBoxLayout;
    autoItem->setLayout(hLayout);
    hLayout->addWidget(autoLabel);
    hLayout->addStretch();
    DSwitchButton *switchbtn = new DSwitchButton(this);
    hLayout->addWidget(switchbtn);
}

void CommonWidget::initTransparencyItem()
{
    transparencyItem = new SettingsItem(this);
    transparencyItem->addBackground();
    DLabel *transparencyLabel = new DLabel(tr("透明度调节"));
    DLabel *numLabel = new DLabel("0");
    QHBoxLayout *hlayout = new QHBoxLayout;
    QVBoxLayout *vLayout = new QVBoxLayout;
    vLayout->setContentsMargins(10,10,10,10);
    transparencyItem->setLayout(vLayout);
    hlayout->addWidget(transparencyLabel,0,Qt::AlignLeft);
    hlayout->addWidget(numLabel,0,Qt::AlignRight);
    DSlider *slider = new DSlider(Qt::Horizontal,this);
    slider->setMouseWheelEnabled(true);
    slider->setHandleVisible(true);
    slider->setMinimum(0);
    slider->setMaximum(100);
    vLayout->addLayout(hlayout);
    vLayout->addWidget(slider);

    connect(slider,&DSlider::valueChanged,[=](int value){
        numLabel->setText(QString::number(value));
    });
}

void CommonWidget::initMinItem()
{
    minItem = new SettingsItem(this);
    minItem->addBackground();
    DLabel *autoLabel = new DLabel(tr("最小化时效果"));
    QHBoxLayout *hLayout = new QHBoxLayout;
    minItem->setLayout(hLayout);
    hLayout->addWidget(autoLabel);
    DComboBox *comboBox = new DComboBox(this);
    comboBox->addItem(tr("缩放"));
    comboBox->addItem(tr("魔灯"));
    hLayout->addWidget(comboBox);
}
