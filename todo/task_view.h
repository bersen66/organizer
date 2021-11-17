#ifndef TASK_VIEW_H
#define TASK_VIEW_H
#include <qwidget.h>

class TaskView : public QWidget
{
    Q_OBJECT
public:
    explicit TaskView(QWidget* parent = 0);
    virtual ~TaskView();
private:

};
#endif // TASK_VIEW_H
