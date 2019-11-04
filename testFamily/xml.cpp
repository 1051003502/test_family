#include "xml.h"
#include "ui_xml.h"
#include <QtXml>
#include "inout.h"
bool isXml(QString data)

{

    //打开或创建文件
    QFile f1("test.xml");
    if(!f1.open(QFile::WriteOnly))return false;
    QTextStream in(&f1);
    in<<data;
    f1.close();
    QFile file("test.xml"); //相对路径、绝对路径、资源路径都行

    if(!file.open(QFile::ReadOnly))return false;
    QDomDocument doc;
    if(!doc.setContent(&file))
    {
        file.close();
        qDebug()<<"xml错误";
        return false;
    }
    file.close();
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
