#include "adding_window.h"
#include <QBoxLayout>

AddingWindow::AddingWindow(QWidget *parent)
    : QWidget(parent),
    date_lbl(new QLabel("date: ")),
    time_lbl(new QLabel("time: ")),
    desc_lbl(new QLabel("description: ")),
    date_edit(new QLineEdit),
    time_edit(new QLineEdit),
    desc_edit(new QLineEdit),
    add_btn(new QPushButton("add")),
    cancel_btn(new QPushButton("cancel"))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    setLayout(layout);

    layout -> addLayout(std::move( MakeLine( {date_lbl, date_edit} ) ) );
    layout -> addLayout(std::move( MakeLine( {time_lbl, time_edit} ) ) );
    layout -> addLayout(std::move( MakeLine( {desc_lbl, desc_edit} ) ) );
    layout -> addLayout(std::move( MakeLine( {add_btn, cancel_btn} ) ) );
}


QHBoxLayout* AddingWindow::MakeLine(const std::vector<QWidget*>& widgets) const {
    QHBoxLayout* result = new QHBoxLayout;
    for (const auto& widget : widgets) {
        result -> addWidget(widget);
    }
    return result;
}
