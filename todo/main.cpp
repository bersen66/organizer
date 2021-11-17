#include "mainwindow.h"
#include <string>
#include <QApplication>



#include "task_view.h"
#include "storage.h"


const std::string file_path = "tasks.txt";

int main(int argc, char *argv[])
{
    Storage st(file_path);
    QApplication a(argc, argv);
    //MainWindow w;
    TaskView tv;
    tv.show();
    //w.show();
    a.exec();
    return 0;
}
