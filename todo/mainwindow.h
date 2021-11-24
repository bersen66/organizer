#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

#include <memory>

#include "storage.h"
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Storage* st, QWidget *parent = nullptr);
    ~MainWindow();
    QListWidget* getTasksLW() const;
    QListWidget* getDatasLW() const;
private slots:
    void on_datas_lw_itemDoubleClicked(QListWidgetItem *item);
    void on_add_task_btn_clicked();
public slots:
    void update_tasks_slot(const Date& date);
    void update_dates_slot();
    void delete_task_slot(const Date& date, const Task& task);
private:

    void UpdateTasks(const Storage& st, const Date& date, QListWidget* dest);
    void UpdateDates(const Storage& st, QListWidget* dest);

    Date current_date;
    Storage* st;
    Ui::MainWindow *ui;
};



#endif // MAINWINDOW_H
