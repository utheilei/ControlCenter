#include "roundcolorview.h"
#include "roundcolorwidget.h"
#include <DApplicationHelper>
#include <DStyle>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

const QList<QString> activeColors = {
    "#D8316C",
    "#FF5D00",
    "#F8CB00",
    "#23C400",
    "#00A48A",
    "#0081FF",
    "#3C02FF",
    "#6A0085",
    "#4D4D4D"
};

RoundColorView::RoundColorView(QWidget *parent) : QWidget(parent)
{
    setMinimumHeight(50);
    QHBoxLayout *colorLayout = new QHBoxLayout();
    setLayout(colorLayout);
    foreach (QString color, activeColors) {
        RoundColorWidget *colorWidget = new RoundColorWidget(QColor(color),this);
        colorLayout->addWidget(colorWidget);
        connect(colorWidget,&RoundColorWidget::clicked,this,&RoundColorView::onChanged);
        m_activeColorsList.append(colorWidget);
    }
}

QColor RoundColorView::currentColor()
{
    return m_colorWidget->roundColor();
}

void RoundColorView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    DStylePainter painter(this);

    QRect r = rect();
    int frame_radius = 18;

    QPainterPath path;
    path.addRoundedRect(r, frame_radius, frame_radius);
    const DPalette &pal = DApplicationHelper::instance()->palette(this);
    painter.fillPath(path, pal.brush(DPalette::ItemBackground));
}

void RoundColorView::onChanged()
{
    RoundColorWidget *widget = qobject_cast<RoundColorWidget *>(sender());

    if(m_colorWidget == widget)
        return;

    m_colorWidget = widget;

    foreach (RoundColorWidget *item, m_activeColorsList) {
        if(widget != item)
            item->setSelected(false);
    }

    emit colorChange(widget->roundColor());
}
