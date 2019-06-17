#include "mainwindow.h"
#include "ui_mainwindow.h"


QString path;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    path = QFileDialog::getOpenFileName(this,"open","../","TXT(*.txt)");
    subwindow_01.show();
}


















