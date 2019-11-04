#include "xml.h"
#include "ui_xml.h"
#include <QtXml>
#include "inout.h"
bool isXml(QString data)
{
    QDomDocument doc;
    if(!doc.setContent(data))return false;
    return true;
}
Xml::Xml(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Xml)
{
    ui->setupUi(this);
    this->setWindowTitle("xml格式校验");
}

Xml::~Xml()
{
    delete ui;
}

void Xml::on_btn_xmlCheck_clicked()
{
    QString data=ui->textEdit_xmlData->toPlainText();
    if(isXml(data)){
        QMessageBox::information(this, ".", "正确的XML格式",
                                      QMessageBox::Ok,QMessageBox::NoButton);
    }else{
        QMessageBox::information(this, ".", "XML格式错误",
                                      QMessageBox::Ok,QMessageBox::NoButton);
    }
}
