#ifndef THEMEWIDGET_H
#define THEMEWIDGET_H

#include <QWidget>
#include <DLabel>

DWIDGET_USE_NAMESPACE

class ThemePix;
class ThemeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ThemeWidget(QWidget *parent = nullptr);

    QString currentTheme();

signals:
    void themeChange(ThemePix *theme);

public slots:
    void onChanged();

private:
    QList<ThemePix *> m_themePixList;
    QMap<ThemePix *, DLabel *> m_map;
    ThemePix *m_themePix = Q_NULLPTR;
};

#endif // THEMEWIDGET_H
