#ifndef TASK_VIEW_H
#define TASK_VIEW_H

#include <qwidget.h>
#include <QCheckBox>
#include <QLabel>
#include <string>

#include "task.h"
#include "date.h"

class TaskView : public QWidget {

    Q_OBJECT
public:
    TaskView(const Date&, QWidget* parent = nullptr);
    virtual ~TaskView();
    void MakePassed();
    void SetDeadline(const std::string& deadline);
    void SetDescription(const std::string& description);
signals:
    void passed(const Date&, const Task&);
private slots:
    void stateChanged();
private:
    Date meta;
    QCheckBox* passed_;
    QLabel* description_;
    QLabel* deadline_;
};
#endif // TASK_VIEW_H
