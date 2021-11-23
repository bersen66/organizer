#ifndef ADD_TASK_WINDOW_H
#define ADD_TASK_WINDOW_H

#include <QDialog>

namespace Ui {
class AddTaskWindow;
}

class AddTaskWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddTaskWindow(QWidget *parent = nullptr);
    ~AddTaskWindow();

private:
    Ui::AddTaskWindow *ui;
};

#endif // ADD_TASK_WINDOW_H
