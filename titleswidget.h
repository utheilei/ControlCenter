#ifndef TITLESWIDGET_H
#define TITLESWIDGET_H

#include <DListView>

DWIDGET_USE_NAMESPACE

class StyledDelegate;
class QStandardItemModel;
class TitlesWidget : public DListView
{
    Q_OBJECT
public:
    explicit TitlesWidget(QWidget *parent = nullptr);

    void addItem(const QIcon &icon, const QString &text);

protected:
    void init();

    void initItems();

signals:

public slots:

private:
    QStandardItemModel *m_model = Q_NULLPTR;
    StyledDelegate *m_itemDelegate = Q_NULLPTR;
    QSize m_size = QSize(170,170);
};

#endif // TITLESWIDGET_H
