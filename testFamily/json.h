#ifndef JSON_H
#define JSON_H

#include <QWidget>
#include "QJsonObject"
#include "QJsonDocument"
namespace Ui {
class Json;
}

class Json : public QWidget
{
    Q_OBJECT

public:
    explicit Json(QWidget *parent = 0);
    ~Json();

private slots:
    void on_btn_jsonCheck_clicked();

private:
    Ui::Json *ui;
};

#endif // JSON_H
