#include "mainwindow.h"

#include <QApplication>
#include <QListWidgetItem>

#include <fstream>
#include "add_task_window.h"
#include "task_view.h"
#include "storage.h"
#include "date.h"


const std::string file_path = "tasks.txt";

void SaveEverithing(const Storage& st) {
    std::ofstream backup_file (file_path, std::ios::out);
    if (backup_file.is_open()) {
        st.Write(backup_file);
    }
    backup_file.close();
}


int main(int argc, char *argv[]) {
    Storage st(file_path);
    QApplication a(argc, argv);

    MainWindow w(&st, nullptr);
    w.show();

    AddTaskWindow tw(nullptr);

    tw.show();


    a.exec();

    SaveEverithing(st);
    return 0;
}
