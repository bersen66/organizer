#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      datas_(new QScrollArea(this)),
      tasks_(new QScrollArea(this))

    //, ui(new Ui::MainWindow)
{
    //datas_ -> setBackgroundRole(QPalette::Dark);
    //tasks_ -> setBackgroundRole(QPalette::Mid);

    //setLayout(new QHBoxLayout);
//    QHBoxLayout* lay = new QHBoxLayout;
//     lay -> addWidget(new QPushButton("b1",this));
//     lay -> addWidget(new QPushButton("b2", this));

//     lay -> addWidget(new QPushButton("b3", this));
//     lay -> addWidget(new QPushButton("b4", this));

//     setLayout(lay);
//    QHBoxLayout* lay = new QHBoxLayout;
//    lay -> addWidget(tasks_);
//    lay -> addWidget(datas_);
//    layout() -> addItem(lay);
//    ui->setupUi(this);
      setLayout(new QHBoxLayout);
      QVBoxLayout *vbox = new QVBoxLayout(this);
      vbox->setSpacing(1);

      QPushButton *settings = new QPushButton("Settings", this);
      settings->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      QPushButton *accounts = new QPushButton("Accounts", this);
      accounts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      QPushButton *loans = new QPushButton("Loans", this);
      loans->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      QPushButton *cash = new QPushButton("Cash", this);
      cash->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      QPushButton *debts = new QPushButton("Debts", this);
      debts->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      vbox->addWidget(settings);
      vbox->addWidget(accounts);
      vbox->addWidget(loans);
      vbox->addWidget(cash);
      vbox->addWidget(debts);

      layout() -> addItem(vbox);

}

MainWindow::~MainWindow()
{
    //delete ui;
}

QScrollArea* MainWindow::GetDatasArea(){
    return datas_;
}

QScrollArea* MainWindow::GetTasksArea(){
    return tasks_;
}

void MainWindow::AddTask(TaskView* task) {
    tasks_-> setWidget(task);
}
