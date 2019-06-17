#include "subwindow.h"
#include "ui_subwindow.h"

subwindow::subwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::subwindow)
{
    ui->setupUi(this);
    this->resize(500,400);
    ui->drawingwindow_01->setMinimumSize(6000,1000);
    setWindowTitle("plot");
}

subwindow::~subwindow()
{
    delete ui;
}
