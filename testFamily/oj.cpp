#include "oj.h"
#include "ui_oj.h"
#include "inout.h"
#include "net.h"
Oj::Oj(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Oj)
{
    ui->setupUi(this);
    this->setWindowTitle("算法程序测试");
    ui->textEdit_code->setFont(QFont(tr("Consolas"), 11));
    ui->textEdit_in->setFont(QFont(tr("Consolas"), 11));
    ui->textEdit_out1->setFont(QFont(tr("Consolas"), 11));
    ui->textEdit_out2->setFont(QFont(tr("Consolas"), 11));

}

Oj::~Oj()
{
    delete ui;
}
/*
 * code 与 in合成json
 */
QString changeToJson(QString code,QString in){
    QString str="{\"code\":\""+code.toUtf8().toBase64()+"\",\"in\":\""+in.toUtf8().toBase64()+"\"}";
    return str;
}

void Oj::on_btn_show_clicked()
{
    QString str1=ui->textEdit_code->toPlainText();//获取框里面的值
    QString str2=ui->textEdit_in->toPlainText();
    QNetworkAccessManager *m_pHttpMgr = new QNetworkAccessManager();
    //设置url
    QString url = "http://152.136.158.218:62002/post/judge/";
    if(ui->codeType->currentIndex()==0)url+="cpp";
    else if(ui->codeType->currentIndex()==1)url+="python";
    else if(ui->codeType->currentIndex()==2)url+="java";
    else if(ui->codeType->currentIndex()==3)url+="golang";
    //设置头信息
    QNetworkRequest requestInfo;
    requestInfo.setUrl(QUrl(url));
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));

    //发送数据
    QByteArray qByteHttpData =changeToJson(str1,str2).toUtf8();

    QNetworkReply *reply =  m_pHttpMgr->post(requestInfo, qByteHttpData);

    QEventLoop eventLoop;
    connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish
    QByteArray responseByte = reply->readAll();
    ui->textEdit_out2->setText( (QString)responseByte);
}


void Oj::on_btn_compare_clicked()
{
    QString s1=ui->textEdit_out1->toPlainText();
    QString s2=ui->textEdit_out2->toPlainText();
    if(s1==s2){
        QMessageBox::information(this, ".", "相同",
                                      QMessageBox::Ok,QMessageBox::NoButton);
    }else{
        QMessageBox::information(this, ".", "不同",
                                      QMessageBox::Ok,QMessageBox::NoButton);
    }
}
