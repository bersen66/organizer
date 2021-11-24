#ifndef ADD_TASK_WINDOW_H
#define ADD_TASK_WINDOW_H

#include <QDialog>
#include <memory>

#include "task.h"
#include "storage.h"
#include "mainwindow.h"
#include "date.h"

namespace Ui {
class AddTaskWindow;
}

class AddTaskWindow : public QDialog
{
    Q_OBJECT

public:
    AddTaskWindow(Storage* st, QWidget *parent = nullptr);
    ~AddTaskWindow();
signals:
    void add_task_signal(const Date& date, const Task& task);
    void add_task_signal();
    void add_date_signal(const Date& date);
private slots:
    void on_add_btn_clicked();

private:
    Storage* storage_ptr;
    Ui::AddTaskWindow* ui;

};

#endif // ADD_TASK_WINDOW_H
