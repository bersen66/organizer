#include <QBoxLayout>


#include "task_view.h"

TaskView::TaskView(QWidget* parent)
    : QWidget(parent), passed_(new QCheckBox(this)),
      deadline_(new QLabel("deadline", this)), description_(new QLabel("description", this))
{
    setLayout(new QVBoxLayout);
    QHBoxLayout* lay = new QHBoxLayout;
    lay -> addWidget(deadline_);
    lay -> addWidget(description_);
    lay -> addWidget(passed_);
    layout() -> addItem(lay);
}

TaskView::~TaskView(){

}

void TaskView::MakePassed(){}

void TaskView::SetDeadline(const std::string& deadline){}

void TaskView::SetDescription(const std::string& description){}
