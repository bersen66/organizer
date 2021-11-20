#include "mainwindow.h"
#include <string>
#include <vector>
#include <QApplication>

#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QListWidget>
#include <scrollable_pannel.h>


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

int main(int argc, char *argv[])
{
    Storage st(file_path);

    QApplication a(argc, argv);

    QMainWindow window;
    window.setGeometry(0, 0, 1000, 640);
    QWidget* widget = new QWidget(&window);
    QHBoxLayout* layout = new QHBoxLayout(widget);

    window.setCentralWidget(widget);
    widget -> setLayout(layout);

    QScrollArea* datas_scroll = new QScrollArea;
    QListWidget* datas_lw = new QListWidget;
    datas_scroll -> setWidget(datas_lw);
    layout -> addWidget(datas_lw);

    QScrollArea* scroll_box =new QScrollArea;
    QListWidget* lw = new QListWidget;

    scroll_box -> setWidget(lw);
    layout -> addWidget(lw);

    ScrollablePannel* pannel = new ScrollablePannel;
    layout -> addWidget(pannel);
    /*
    for (int i = 0; i < 30; i++) {
        TaskView* tw = new TaskView;
        tw -> SetDeadline("21.21.21");
        tw -> SetDescription("Aboba abooooooba" + std::to_string(i));

        pannel -> AddItem(tw);

        // Добавление элемента в лист
        QListWidgetItem* itm = new QListWidgetItem;
        itm -> setSizeHint(tw->size());
        lw -> addItem(itm);
        lw -> setItemWidget(itm, tw);
    }

    for (int i = 0; i < 13; i++) {
        QListWidgetItem* itm = new QListWidgetItem;
        itm ->setText("Data: " + QString::number(i));
        datas_lw -> addItem(itm);
    }
    */


    for (const auto& [data, task_info] : st) {
        // Распаковка содержимого хранилища
        QListWidgetItem* data_item = new QListWidgetItem;
        data_item ->setText(data.ToString().c_str());
        datas_lw -> addItem(data_item);
    }


    UpdateTasks(st, st.begin()->first,lw);

//    for (const auto& task : hello_screen_tasks_data) {
//        TaskView* tw = new TaskView;
//        tw -> SetDeadline(task.deadline.ToString());
//        tw -> SetDescription(task.description);

//        QListWidgetItem* itm = new QListWidgetItem;
//        itm -> setSizeHint(tw->size());
//        lw -> addItem(itm);
//        lw -> setItemWidget(itm, tw);
//    }

    window.show();

    a.exec();


    return 0;
}
