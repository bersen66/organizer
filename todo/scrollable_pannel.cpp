#include "scrollable_pannel.h"
#include <QScrollArea>
#include <QWidgetList>

ScrollablePannel::ScrollablePannel(QWidget *parent)
    : QWidget(parent), scroll_area_(new QScrollArea), widgets_(new QListWidget)
{
     scroll_area_ -> setWidget(widgets_);
}



void ScrollablePannel::AddItem(QWidget* widget) {
    QListWidgetItem* item = new QListWidgetItem;
    item -> setSizeHint(widget -> size());
    widgets_ -> addItem(item);
    widgets_ -> setItemWidget(item, widget);
}