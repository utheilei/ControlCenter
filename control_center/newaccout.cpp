#include "newaccout.h"
#include "circlebutton.h"
#include "avatardel.h"
#include "circleview.h"
#include <DLabel>
#include <DFloatingButton>
#include <QBoxLayout>
#include <DLineEdit>
#include <DSuggestButton>
#include <DPushButton>
#include <DApplicationHelper>
#include <QDebug>
#include <QBitmap>

NewAccout::NewAccout(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *vlayout = new QVBoxLayout;
    this->setLayout(vlayout);

    DLabel *label = new DLabel(this);
    label->setText(tr("新账户"));

    //DFloatingButton *btn4 = new DFloatingButton(DStyle::SP_IncreaseElement,this);
    //btn4->setFixedSize(40,40);
    //btn4->setBackgroundRole(QPalette::Button);

    circleWidget = new circleView(this);
    initAccoutWidget();

    DLabel *label1 = new DLabel(this);
    label1->setText(tr("用户名："));
    DLabel *label2 = new DLabel(this);
    label2->setText(tr("全名："));
    DLabel *label3 = new DLabel(this);
    label3->setText(tr("密码："));
    DLabel *label4 = new DLabel(this);
    label4->setText(tr("重复密码："));

    lineedit = new DLineEdit;
    lineedit->lineEdit()->setPlaceholderText(tr("必填"));

    lineedit1 = new DLineEdit;
    lineedit1->lineEdit()->setPlaceholderText(tr("选填"));

    edit = new DPasswordEdit;
    edit->lineEdit()->setPlaceholderText(tr("必填"));
    edit1 = new DPasswordEdit;
    edit1->lineEdit()->setPlaceholderText(tr("必填"));

    QHBoxLayout *lyout = new QHBoxLayout;
    DPushButton *cancelbtn = new DPushButton(tr("取消"));
    DSuggestButton *creatbtn = new DSuggestButton(tr("创建"));
    lyout->addWidget(cancelbtn);
    lyout->addWidget(creatbtn);

    vlayout->addWidget(label);
    vlayout->setAlignment(label,Qt::AlignHCenter);
    vlayout->addWidget(circleWidget);
    vlayout->addWidget(label1);
    vlayout->addWidget(lineedit);
    vlayout->addWidget(label2);
    vlayout->addWidget(lineedit1);
    vlayout->addWidget(label3);
    vlayout->addWidget(edit);
    vlayout->addWidget(label4);
    vlayout->addWidget(edit1);
    vlayout->addSpacing(10);
    vlayout->addLayout(lyout);

    m_msg = new DMessageBox(DMessageBox::Icon::Information,
                            tr("警告"), tr("密码输入不一致，请重新输入！"),
                            DMessageBox::StandardButton::Ok
                            | DMessageBox::StandardButton::Cancel, this);

    connect(cancelbtn,&DPushButton::clicked,[=](){
        emit signalcancel();
    });
    connect(creatbtn,&DPushButton::clicked,this,&NewAccout::slotCreatAccout);

    connect(circleWidget,&circleView::currentWidget,[=](QWidget *w){
        CircleButton *btn = qobject_cast<CircleButton *>(w);
        m_pixmap = btn->pixmap();
    });

}

void NewAccout::initAccoutWidget()
{
    QString iconPath = "";
    for (int j=0;j<2;j++) {
        for (int i=0;i<5;i++) {
            iconPath = QString(":/images/images%1.png").arg(i);
            if(i==0)
                iconPath = QString(":/images/images.png");
            CircleButton *circle = new CircleButton(QPixmap(iconPath));
            circleWidget->addWidget(circle);
        }
    }
}

void NewAccout::slotCreatAccout()
{
    if(!lineedit->text().isEmpty()){
        m_accout = lineedit->text();
    }
    m_name = lineedit1->text();
    if(!edit->text().isEmpty()){
        m_password = edit->text();
    }
    if(lineedit->text().isEmpty()
            ||edit->text().isEmpty()
            ||edit1->text().isEmpty()){
        m_msg->setText(tr("用户名/密码不能为空！"));
        m_msg->show();
        return;
    }
    if(edit->text() != edit1->text()){
        m_msg->setText(tr("密码输入不一致，请重新输入！"));
        m_msg->show();
        return;
    }
    emit signalNewaccout(m_pixmap,m_accout,m_name,m_password);
    lineedit->clear();
    lineedit1->clear();
    edit->clear();
    edit1->clear();
}
