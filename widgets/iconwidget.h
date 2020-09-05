#ifndef ICONWIDGET_H
#define ICONWIDGET_H

#include <QWidget>

class QHBoxLayout;

class IconWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IconWidget(QWidget *parent = nullptr);

    void setIcon(QList<QIcon> iconList);

    void setIconSize(QSize size);

    inline QHBoxLayout *layout() const;

    void setSpacing(int margin);

signals:

public slots:

private:
    QHBoxLayout *m_layout = Q_NULLPTR;
    QSize m_size = QSize(40, 40);
};

#endif // ICONWIDGET_H
