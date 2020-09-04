#include "fullnameedit.h"

#include <QLineEdit>
#include <QDebug>
#include <QFocusEvent>

FullNameEdit::FullNameEdit(QWidget *parent) : QWidget(parent)
{
    setFocusPolicy(Qt::StrongFocus);
    layout = new QHBoxLayout;
    setLayout(layout);
    layout->setMargin(0);
    layout->setContentsMargins(0,0,0,0);

    m_edit = new DImageButton(this);
    m_edit->setNormalPic(":/images/edit_normal.png");
    m_edit->setHoverPic(":/images/edit_hover.png");
    m_edit->setPressPic(":/images/edit_press.png");

    label = new DLabel(tr("设置全名"),this);
    label->setEnabled(false);
    lineEdit = new QLineEdit(this);
    lineEdit->hide();
    lineEdit->installEventFilter(this);
    lineEdit->setFocusPolicy(Qt::StrongFocus);

    layout->addStretch();
    layout->addWidget(label);
    layout->addWidget(m_edit);
    layout->addWidget(lineEdit);
    layout->addStretch();

    connect(m_edit,&DImageButton::clicked,this,&FullNameEdit::changeWidget);
    connect(lineEdit,&QLineEdit::returnPressed,this,&FullNameEdit::loseFocus);
}

bool FullNameEdit::eventFilter(QObject *target, QEvent *event)
{
    if (target == lineEdit)
    {
        if (event->type() == QEvent::FocusOut)
        {
            QFocusEvent *focusEvent = static_cast<QFocusEvent *>(event);
            loseFocus();
        }
    }

    return QWidget::eventFilter(target, event);
}

void FullNameEdit::changeWidget()
{
    label->hide();
    m_edit->hide();
    layout->removeItem(layout->itemAt(0));
    layout->removeItem(layout->itemAt(layout->count()-1));
    lineEdit->show();
    lineEdit->setFocus();
}

void FullNameEdit::loseFocus()
{
    lineEdit->hide();
    label->show();
    m_edit->show();

    if (layout->count() < 5) {
        layout->insertStretch(0);
        layout->insertStretch(layout->count());
    }

    if(lineEdit->text().isEmpty()) {
        label->setText(tr("设置全名"));
    } else {
        QString name = lineEdit->text();
        label->setText(name);
        emit nameChanged(name);
    }
}
