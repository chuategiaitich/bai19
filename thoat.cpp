#include "thoat.h"
#include "ui_thoat.h"
#include <QApplication>
Thoat::Thoat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Thoat)
{
    ui->setupUi(this);
}

Thoat::~Thoat()
{
    delete ui;
}

void Thoat::on_pushButton_clicked()
{
    qApp->closeAllWindows();
}


void Thoat::on_pushButton_2_clicked()
{
    close();
}

