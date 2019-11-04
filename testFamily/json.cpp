#include "json.h"
#include "ui_json.h"
#include "inout.h"
Json::Json(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Json)
{
    ui->setupUi(this);
    this->setWindowTitle("json格式校验");
    ui->textEdit_jsonData->setFont(QFont(tr("Consolas"), 11));
}

Json::~Json()
{
    delete ui;
}
bool isJson(QString jsonString){
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonString.toStdString().data());
    //jsonString.toLocal8Bit().data()
    if(jsonDocument.isNull()){
        return false;
    }
    return true;
}
void Json::on_btn_jsonCheck_clicked()
{
    QString data=ui->textEdit_jsonData->toPlainText();
    if(isJson(data)){
        QMessageBox::information(this, ".", "正确的JSON格式",
                                      QMessageBox::Ok,QMessageBox::NoButton);
    }else{
        QMessageBox::information(this, ".", "JSON格式错误",
                                      QMessageBox::Ok,QMessageBox::NoButton);
    }

}
