#include <QBoxLayout>

#include <iostream>
#include "task_view.h"
#include "date.h"

TaskView::TaskView(const Date& d, QWidget* parent)
    : QWidget(parent), passed_(new QCheckBox(this)), meta(d),
      deadline_(new QLabel("", this)), description_(new QLabel("", this))
{
    this->setFixedHeight(50);

    passed_ ->sizeHint();
    setLayout(new QVBoxLayout);
    QHBoxLayout* lay = new QHBoxLayout; 

    lay -> addWidget(deadline_);
    lay -> addWidget(description_);
    lay -> addWidget(passed_);
    layout() -> addItem(lay);

    QObject::connect(
                passed_,
                SIGNAL(stateChanged(int)),
                this,
                SLOT(stateChanged())
    );
}


void TaskView::stateChanged() {
    std::cout << "stateChanged" << std::endl;

    TimeKeeper kp = ParseTime(
                 std::istringstream(std::move(deadline_ ->text().toStdString()))
                );

   QString str = description_ -> text();
   emit passed(meta, Task(kp, str.toStdString()));

}

TaskView::~TaskView(){

}

void TaskView::MakePassed(){}

void TaskView::SetDeadline(const std::string& deadline){
    deadline_->setText(deadline.c_str());
}

void TaskView::SetDescription(const std::string& description){
    description_->setText(description.c_str());
}
