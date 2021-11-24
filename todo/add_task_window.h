#ifndef ADD_TASK_WINDOW_H
#define ADD_TASK_WINDOW_H

#include <QDialog>
#include <memory>

#include "storage.h"

namespace Ui {
class AddTaskWindow;
}

class AddTaskWindow : public QDialog
{
    Q_OBJECT

public:
    AddTaskWindow(Storage* st, QWidget *parent = nullptr);
    ~AddTaskWindow();


private slots:
    void on_add_btn_clicked();

private:
    Storage* storage_ptr;
    Ui::AddTaskWindow *ui;
};

#endif // ADD_TASK_WINDOW_H
