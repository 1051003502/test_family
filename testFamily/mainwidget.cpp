#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "QWidget"
#include "http.h"
#include "json.h"
#include "oj.h"
#include "xml.h"
MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->setWindowTitle("测试全家桶");
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_btn_http_clicked()
{
    QWidget* widget=new Http();
    widget->show();
}

void MainWidget::on_btn_oj_clicked()
{
    QWidget* widget=new Oj();
    widget->show();
}

void MainWidget::on_btn_json_clicked()
{
    QWidget* widget=new Json();
    widget->show();
}

void MainWidget::on_btn_xml_clicked()
{
    QWidget* widget=new Xml();
    widget->show();
}
