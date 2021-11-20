#ifndef SCROLLABLEPANNEL_H
#define SCROLLABLEPANNEL_H

#include <QWidget>
#include <QScrollArea>
#include <QListWidget>

class ScrollablePannel : public QWidget
{
    Q_OBJECT
public:
    explicit ScrollablePannel(QWidget *parent = nullptr);
    void AddItem(QWidget* widget);
signals:
private:
    QScrollArea* scroll_area_;
    QListWidget* widgets_;
};

#endif // SCROLLABLEPANNEL_H
