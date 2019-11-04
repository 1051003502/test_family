#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "oj.h"
#include "QWidget"
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

void MainWindow::on_btn_oj_clicked()
{
    QWidget* widget_oj= new oj();
    widget_oj->show();
}
