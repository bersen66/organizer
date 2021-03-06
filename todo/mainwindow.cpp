#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QListWidget>
#include <QListWidgetItem>

#include <sstream>

#include "task_view.h"
#include "storage.h"
#include "date.h"

#include "add_task_window.h"

void MainWindow::UpdateTasks(const Storage& st, const Date& date, QListWidget* dest) {
    dest->clear();
    if (st.Empty())
        return;
    try {
        auto screen_data = st.GetDailyTasks(date);
        for (const auto& task : screen_data) {
            TaskView* tw = new TaskView(date);
            tw -> SetDeadline(task.deadline.ToString());
            tw -> SetDescription(task.description);
            QObject::connect(
                        tw,
                        SIGNAL(passed(Date, Task)),
                        this,
                        SLOT(delete_task_slot(const Date&, const Task&))
           );


            QListWidgetItem* itm = new QListWidgetItem;
            itm -> setSizeHint(tw->size());
            dest -> addItem(itm);
            dest -> setItemWidget(itm, tw);
        }
    } catch(...){return;}


    std::cout << "On update tasks!" << std::endl;
}

void MainWindow::UpdateDates(const Storage& st, QListWidget* dest) {
    dest->clear();
    if (st.Empty())
        return;
    for (auto& [data, task_info] : st) {
        // Распаковка содержимого хранилища
        QListWidgetItem* data_item = new QListWidgetItem;
        data_item ->setText(data.ToString().c_str());
        dest -> addItem(data_item);
    }
    std::cout << "On update dates!" << std::endl;
}

MainWindow::MainWindow(Storage* st, QWidget *parent)
    : QMainWindow(parent), st(st), current_date(st->begin()->first)
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



void MainWindow::on_datas_lw_itemDoubleClicked(QListWidgetItem *item)
{
    std::istringstream in(item->text().toStdString());

    Date d = ParseDate(in);
    UpdateTasks(*st, std::move(d), ui->tasks_lw);
}


void MainWindow::update_tasks_slot(const Date& date) {
    ui->datas_lw->clear();
    current_date = date;
    std::cout << "In update_dates slot!" << std::endl;
    UpdateTasks(*st, current_date, ui->tasks_lw);
}

void MainWindow::update_dates_slot() {
    ui->datas_lw->clear();
    std::cout << "In update_dates slot!" << std::endl;
    UpdateDates(*st, ui->datas_lw);
}

void MainWindow::delete_task_slot(const Date& date, const Task& task) {
    std::cout << "in delete task slot" << std::endl;
    st->RemoveTask(date, task);
    UpdateTasks(*st, date, ui->tasks_lw);
    UpdateDates(*st, ui->datas_lw);

}



void MainWindow::on_add_task_btn_clicked()
{
    AddTaskWindow* tw = new AddTaskWindow(st, nullptr);
    tw->setModal(true);
    QObject::connect(tw,
            SIGNAL(add_task_signal(const Date&, const Task&)),
            this,
            SLOT(update_tasks_slot(const Date&))
    );

    QObject::connect(tw,
                  SIGNAL(add_task_signal(const Date&, const Task&)),
                  this,
                  SLOT(update_dates_slot()));
    tw->exec();
}

