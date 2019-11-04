#ifndef HTTP_H
#define HTTP_H

#include <QWidget>

namespace Ui {
class Http;
}

class Http : public QWidget
{
    Q_OBJECT

public:
    explicit Http(QWidget *parent = 0);
    ~Http();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Http *ui;
};

#endif // HTTP_H
