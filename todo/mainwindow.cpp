#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QListWidget>
#include <QListWidgetItem>

#include <sstream>

#include "task_view.h"
#include "storage.h"
#include "date.h"

#include "add_task_window.h"

MainWindow::MainWindow(Storage* st, QWidget *parent)
    : QMainWindow(parent), st(st)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    UpdateDates(*(this->st), ui->datas_lw);

}

QListWidget* MainWindow::getTasksLW() const {
    return ui->tasks_lw;
}

QListWidget* MainWindow::getDatasLW() const {
    return ui->datas_lw;
}


MainWindow::~MainWindow()
{
    delete ui;
}

void UpdateTasks(const Storage& st, const Date& date, QListWidget* dest) {
    dest->clear();
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

void UpdateDates(const Storage& st, QListWidget* dest) {
    dest->clear();
    for (auto& [data, task_info] : st) {
        // Распаковка содержимого хранилища
        QListWidgetItem* data_item = new QListWidgetItem;
        data_item ->setText(data.ToString().c_str());
        dest -> addItem(data_item);
    }
}

void MainWindow::on_datas_lw_itemDoubleClicked(QListWidgetItem *item)
{
    std::istringstream in(item->text().toStdString());

    Date d = ParseDate(in);
    UpdateTasks(*st, std::move(d), ui->tasks_lw);
}


void MainWindow::on_add_task_btn_clicked()
{
    AddTaskWindow tw;
    tw.setModal(true);
    tw.exec();
}

