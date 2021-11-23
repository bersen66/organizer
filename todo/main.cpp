#include "mainwindow.h"
#include <string>
#include <QApplication>
#include <QPushButton>
#include <QBoxLayout>
#include <QListWidget>

#include "task_view.h"
#include "storage.h"

const std::string file_path = "tasks.txt";

void UpdateTasks(const Storage& st, const Date& date, QListWidget* dest) {
    auto screen_data = st.GetDailyTasks(date);
    for (const auto& task : screen_data) {
        TaskView* tw = new TaskView;
        tw -> SetDeadline(task.deadline.ToString());
        tw -> SetDescription(task.description);

        QListWidgetItem* itm = new QListWidgetItem;
        itm -> setSizeHint(tw->size());
        dest -> addItem(itm);
        dest -> setItemWidget(itm, tw);
    }
}

void UpdateDates(const Storage& st,QListWidget* dest) {
    for (auto& [data, task_info] : st) {
        // Распаковка содержимого хранилища
        QListWidgetItem* data_item = new QListWidgetItem;
        data_item ->setText(data.ToString().c_str());
        dest -> addItem(data_item);
    }
}

int main(int argc, char *argv[])
{
    Storage st(file_path);

    QApplication a(argc, argv);

    QMainWindow window;
    window.setGeometry(0, 0, 1200, 600);
    QWidget* widget = new QWidget(&window);
    QHBoxLayout* layout = new QHBoxLayout(widget);
    window.setCentralWidget(widget);
    widget -> setLayout(layout);

    QVBoxLayout* left_pannel = new QVBoxLayout;

    QPushButton* add_button = new QPushButton;


    QScrollArea* datas_scroll = new QScrollArea;
    QListWidget* datas_lw = new QListWidget;
    datas_scroll -> setWidget(datas_lw);
    datas_scroll -> setWidgetResizable(true); // важно!
    datas_scroll -> setMaximumWidth(150);


    QScrollArea* tasks_scroll =new QScrollArea;
    QListWidget* tasks_lw = new QListWidget;
    tasks_scroll -> setWidget(tasks_lw);
    tasks_scroll -> setWidgetResizable(true); // важно!

    UpdateDates(st, datas_lw);
    UpdateTasks(st, (st.begin())->first,tasks_lw);


    //layout -> addWidget(datas_lw);
    //left_pannel -> addWidget(datas_scroll);

    left_pannel -> addWidget(datas_scroll);
    left_pannel -> addWidget(add_button);
    layout -> addLayout(left_pannel);
    //layout -> addWidget(tasks_lw);
    layout -> addWidget(tasks_scroll);
    window.show();

    a.exec();

    return 0;
}
