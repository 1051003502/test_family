#include "http.h"
#include "ui_http.h"
#include "net.h"
#include "inout.h"
Http::Http(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Http)
{
    ui->setupUi(this);
    this->setWindowTitle("http接口测试");
}

Http::~Http()
{
    delete ui;
}

void Http::on_pushButton_clicked()
{
    QString url=ui->lineEdit_url->text();
    QString head=ui->lineEdit_head->text();
    int type=ui->comboBox_type->currentIndex();
    QString data1=ui->textEdit_data1->toPlainText();
    QNetworkAccessManager *m_pHttpMgr = new QNetworkAccessManager();
    QNetworkRequest requestInfo;
    requestInfo.setUrl(QUrl(url));
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant(head));

    //发送数据
    QNetworkReply *reply;

    if(type==0){
        reply =  m_pHttpMgr->get(requestInfo);

    }else if(type==1){
        reply =  m_pHttpMgr->post(requestInfo, data1.toUtf8());
    }


    QEventLoop eventLoop;
    connect(reply, SIGNAL(finished()), &eventLoop, SLOT(quit()));
    eventLoop.exec();       //block until finish
    QByteArray responseByte = reply->readAll();
    ui->textEdit_data2->setText( (QString)responseByte);
}
