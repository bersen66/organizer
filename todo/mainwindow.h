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

private:
    Storage* st;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
