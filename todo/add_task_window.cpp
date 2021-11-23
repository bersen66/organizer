#include "add_task_window.h"
#include "ui_add_task_window.h"

AddTaskWindow::AddTaskWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTaskWindow)
{
    ui->setupUi(this);
}

AddTaskWindow::~AddTaskWindow()
{
    delete ui;
}
