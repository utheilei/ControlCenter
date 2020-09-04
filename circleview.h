#ifndef CIRCLEVIEW_H
#define CIRCLEVIEW_H

#include <QWidget>
#include <QBoxLayout>

class circleView : public QWidget
{
    Q_OBJECT
public:
    explicit circleView(QWidget *parent = nullptr);

    void init();

    void addWidget(QWidget *w);

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;

    void updateWidget(QWidget *w, int count, int colum);

signals:
    void currentWidget(QWidget *w);

public slots:

private:
    QVBoxLayout *mainLayout;
    int m_count = 0;
};

#endif // CIRCLEVIEW_H
