#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>
#include "drawing.h"

namespace Ui {
class subwindow;
}

class subwindow : public QWidget
{
    Q_OBJECT

public:
    explicit subwindow(QWidget *parent = 0);
    ~subwindow();

private:
    Ui::subwindow *ui;
    //drawing drawingwindow_01;

};

#endif // SUBWINDOW_H
