#ifndef ADDINGWINDOW_H
#define ADDINGWINDOW_H

#include <vector>

#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

#include "task.h"

class AddingWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AddingWindow(QWidget *parent = nullptr);


signals:

private:
    QLabel* date_lbl;
    QLabel* time_lbl;
    QLabel* desc_lbl;

    QLineEdit* date_edit;
    QLineEdit* time_edit;
    QLineEdit* desc_edit;

    QPushButton* add_btn;
    QPushButton* cancel_btn;


    QHBoxLayout* MakeLine(const std::vector<QWidget*>& widgets) const;

};

#endif // ADDINGWINDOW_H
