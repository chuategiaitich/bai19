#ifndef THOAT_H
#define THOAT_H

#include <QDialog>

namespace Ui {
class Thoat;
}

class Thoat : public QDialog
{
    Q_OBJECT

public:
    explicit Thoat(QWidget *parent = nullptr);
    ~Thoat();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Thoat *ui;
};

#endif // THOAT_H
