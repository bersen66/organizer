#include "add_task_window.h"
#include "ui_add_task_window.h"

#include <iostream>
#include <sstream>

#include "storage.h"
#include "date.h"
#include "time_keeper.h"

#include "mainwindow.h"


AddTaskWindow::AddTaskWindow(Storage* st, QWidget *parent) :
    QDialog(parent),
    storage_ptr(st),
    ui(new Ui::AddTaskWindow)
{
    ui->setupUi(this);
}

AddTaskWindow::~AddTaskWindow()
{
    delete ui;
}

void AddTaskWindow::on_add_btn_clicked()
{
     Date d = ParseDate(
                 std::istringstream(ui->date_edit->text().toStdString()),
                 DateFormat::DMY
                 );
     std::cout << d << std::endl;

     std::cout << ui->time_edit->text().toStdString() << std::endl;

     TimeKeeper kp = ParseTime(
                  std::istringstream(std::move(ui->time_edit->text().toStdString()))
                 );
     std::cout << kp << std::endl;

    QString str = ui->desript_edit->text();
    std::cout << str.toStdString() << std::endl;


    storage_ptr->Add(d,Task(kp, str.toStdString()));

    emit add_task_signal(d,Task(kp, str.toStdString()));
// TODO: Обновление листов в главном окне




}

