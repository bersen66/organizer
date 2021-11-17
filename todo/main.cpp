#include "mainwindow.h"
#include <string>
#include <vector>
#include <QApplication>



#include "task_view.h"
#include "storage.h"


const std::string file_path = "tasks.txt";

int main(int argc, char *argv[])
{
    Storage st(file_path);
    QApplication a(argc, argv);
    MainWindow w;
#if 1
    std::vector<TaskView*> tw;
    for (int i = 0; i < 10; i++) {
        tw.push_back(new TaskView);
        tw.back()->SetDeadline("21.21.12");
        tw.back()->SetDescription("Dora concert");

    }
    for (int i = 0; i < 10; i++) {
        tw[i]->show();
    }
#endif
    TaskView tv;
    tv.show();
    w.show();
    a.exec();
    return 0;
}
