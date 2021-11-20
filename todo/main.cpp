#include "mainwindow.h"
#include <string>
#include <vector>
#include <QApplication>

#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QListWidget>


#include "task_view.h"
#include "storage.h"


const std::string file_path = "tasks.txt";

int main(int argc, char *argv[])
{
    Storage st(file_path);
    QApplication a(argc, argv);
 #if 0  //MainWindow w;
{
    std::vector<TaskView*> tw;
    for (int i = 0; i < 10; i++) {
        tw.push_back(new TaskView);
        tw.back()->SetDeadline("21.21.12");
        tw.back()->SetDescription("Dora concert");
        w.AddTask(tw[i]);

    }
    for (int i = 0; i < 10; i++) {
        tw[i]->show();
    }


    QWidget *window = new QWidget;

    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    //QHBoxLayout *lay = new QHBoxLayout(window);
    QVBoxLayout *layout = new QVBoxLayout(window);
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    window->show();
    //TaskView tv;
    //tv.show();
    //w.show();
    a.exec();
}
#endif



    QMainWindow window;
    QWidget* widget = new QWidget(&window);
    QHBoxLayout* layout = new QHBoxLayout(widget);

    window.setCentralWidget(widget);
    widget -> setLayout(layout);

    //QGroupBox* box = new QGroupBox("tasks", widget);
    //QVBoxLayout* box_layout = new QVBoxLayout(box);


    QGroupBox* datas_ = new QGroupBox("days", widget);

    QScrollArea* scroll_box =new QScrollArea;
    QListWidget* lw = new QListWidget;

    scroll_box -> setWidget(lw);
    layout -> addWidget(lw);

    for (int i = 0; i < 30; i++) {
        TaskView* tw = new TaskView;
        tw -> SetDeadline("21.21.21");
        tw -> SetDescription("Aboba abooooooba" + std::to_string(i));

        QListWidgetItem* itm = new QListWidgetItem;
        itm -> setSizeHint(tw->size());
        lw -> addItem(itm);
        lw -> setItemWidget(itm, tw);
    }
    /*
    QScrollArea* scroll = new QScrollArea();
    scroll ->setWidgetResizable(false);
    scroll -> setWidget(box);
    layout -> addWidget(scroll);
    */


    layout -> addWidget(datas_);
    //layout -> addWidget(box);





    window.show();

    a.exec();
    return 0;
}
