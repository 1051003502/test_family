#ifndef XML_H
#define XML_H

#include <QWidget>

namespace Ui {
class Xml;
}

class Xml : public QWidget
{
    Q_OBJECT

public:
    explicit Xml(QWidget *parent = 0);
    ~Xml();

private slots:
    void on_btn_xmlCheck_clicked();

private:
    Ui::Xml *ui;
};

#endif // XML_H
