#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>

#include "task_view.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QScrollArea* GetDatasArea();
    QScrollArea* GetTasksArea();
    void AddTask(TaskView* task);
    void AddData();
private:
    //Ui::MainWindow *ui;
    QScrollArea* datas_;
    QScrollArea* tasks_;
};
#endif // MAINWINDOW_H
