#ifndef OJ_H
#define OJ_H

#include <QWidget>

namespace Ui {
class Oj;
}

class Oj : public QWidget
{
    Q_OBJECT

public:
    explicit Oj(QWidget *parent = 0);
    ~Oj();

private slots:
    void on_btn_show_clicked();

    void on_btn_compare_clicked();

private:
    Ui::Oj *ui;
};

#endif // OJ_H
