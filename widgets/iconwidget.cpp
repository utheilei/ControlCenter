#include "iconwidget.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>

IconWidget::IconWidget(QWidget *parent) : QWidget(parent)
{
    m_layout = new QHBoxLayout;
    setLayout(m_layout);
    m_layout->setContentsMargins(0,0,0,0);
    setAttribute(Qt::WA_TransparentForMouseEvents);
}

void IconWidget::setIcon(QList<QIcon> iconList)
{
    foreach (auto icon, iconList) {
        QLabel *label = new QLabel(this);
        label->setPixmap(icon.pixmap(m_size));
        m_layout->addWidget(label);
    }
}

void IconWidget::setIconSize(QSize size)
{
    m_size = size;
}

QHBoxLayout *IconWidget::layout() const
{
    return m_layout;
}

void IconWidget::setSpacing(int margin)
{
    m_layout->setSpacing(margin);
}
