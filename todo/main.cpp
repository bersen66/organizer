#include "mainwindow.h"

#include <QApplication>
#include "storage.h"
#include <string>

const std::string file_path = "tasks.txt";

int main(int argc, char *argv[])
{
    Storage st(file_path);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
    return 0;
}
