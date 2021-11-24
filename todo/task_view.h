#ifndef TASK_VIEW_H
#define TASK_VIEW_H

#include <qwidget.h>
#include <QCheckBox>
#include <QLabel>
#include <string>

class TaskView : public QWidget {

    Q_OBJECT
public:
    explicit TaskView(QWidget* parent = nullptr);
    virtual ~TaskView();
    void MakePassed();
    void SetDeadline(const std::string& deadline);
    void SetDescription(const std::string& description);

private:
    QCheckBox* passed_;
    QLabel* description_;
    QLabel* deadline_;
};
#endif // TASK_VIEW_H
