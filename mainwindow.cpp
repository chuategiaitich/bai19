#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QCloseEvent>
#include <QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    value=0;
}


MainWindow::~MainWindow()
{
    delete ui;
}


//void MainWindow::closeEvent(QCloseEvent *event)
//{
//    if(QMessageBox::question(this,"Comfirm","Bạn có muốn thoát không?")==QMessageBox::No)
//    {
//        event->ignore();
//    }
//}

void MainWindow::on_Button_close_clicked() //mở cửa sổ thoát
{
    //    Thoat thoat;
    //    thoat.setModal(true);
    //    thoat.exec();
    thoat = new Thoat(this);
    thoat->show();
}


void MainWindow::on_lineEdit_returnPressed() //nhập giá trị bằng phím enter
{
    QString str = ui->lineEdit->text();
    int numberr = str.toInt();
    if(numberr == 0)
        return;
    ui->listWidget->addItem(QString::number(numberr));
    ui->lineEdit->clear();
}


void MainWindow::on_Botton_nhap_clicked() //nhập giá trị bằng Button
{
    //    laygiatri();
    //    vietketqua(result);

    //    QString value = ui -> lineEdit -> text();
    //    int numberr = value.toInt();
    //    QString str;
    //    str = str + QString::number(numberr) + "\n";
    //    ui->textEdit->setText(QString("%1").arg(str));

    //    if(number == 0)
    //    {
    //        ui->textEdit->setText(QString(text));
    //    }
    //    else
    //    {
    //        ui->textEdit->setText(QString("%1").arg(number));
    //    }
    QString value = ui -> lineEdit -> text();
    int numberr = value.toInt();
    if(numberr == 0)
        return ;
    ui->listWidget->addItem(QString::number(numberr));
    ui->lineEdit->clear();
}


void MainWindow::on_Botton_reset_clicked() //reset giá trị
{
    ui->listWidget->selectAll();
    qDeleteAll(ui->listWidget->selectedItems());
}


void MainWindow::on_Button1_clicked() //tăng mỗi phần tử lên 2
{
    int length=ui->listWidget->count();
    int a[10]{};
    int n[10]{};
    for (int i=0 ; i<length ; i++)
    {
        a[i] = ui->listWidget->item(i)->text().toInt();
        QListWidgetItem *it = new QListWidgetItem();
        for(int j=0 ; j<length ; j++)
        {
            n[j] = a[i] + 2;
            ui->listWidget->item(i)->setSelected(true) /*selectAll()*/;
            it->setText(QString("%1").arg(n[j]));
//            it->setData(Qt::UserRole,n);
//            qDeleteAll(ui->listWidget->selectedItems());
            ui->listWidget->addItem(it);
        }
//        QStringList str;
//        str = QString::number(n).toStdString();

        /*addItems(QString::number(n))*//*item(i)->setText(QString("%1").arg(n));*/
    }
    qDeleteAll(ui->listWidget->selectedItems());
}


int MainWindow::kiemtrachanle(int s) //hàm ktra chẵn lẻ
{
    int check=1; //lẻ = 1, chẵn = 0
    if(s % 2 == 0)
    {
        check = 0;
    }
    return check;
}


void MainWindow::on_Button2_clicked() //chọn số chẵn đầu
{
    int length = ui->listWidget->count();
    int a[10]{};
    for(int i=0 ; i<length ; i++)
    {
        a[i] = ui -> listWidget -> item(i) -> text().toInt();
        if(kiemtrachanle(a[i])==0)
        {
            ui->listWidget->item(i)->setSelected(true);
            break;
        }
    }
}


void MainWindow::on_Button3_clicked() //chọn số lẻ cuối
{
    int length=ui->listWidget->count();
    int a[10]{};
    for (int i = 0 ; i < length ; i++) {
        a[i] =  ui->listWidget->item(i)->text().toInt();
    }
    for(int i=length-1;i>=0;i--)
    {
        if(kiemtrachanle(a[i])==1)
        {
            ui->listWidget->item(i)->setSelected(true);
            break;
            //            QMessageBox msb;
            //            QString str;
            //            str= QString::number(a[i]);
            //            msb.setText(QString("Số lẻ cuối cùng là: %1").arg(str));
            //            msb.exec();
        }
    }
}


void MainWindow::on_Button4_clicked() //xoá phần tử đang chọn
{
//        if(numselected != -1)
//        {
//        QListWidgetItem *item = ui->listWidget->takeItem(numselected);
//        delete item;
//        ui->listWidget->setCurrentRow(-1);
//        }
//    QListWidgetItem *item = nullptr;
//    item=ui->listWidget->selectedItems();
//    int n=ui->listWidget->selectedItems().data().toInt();
    qDeleteAll(ui->listWidget->selectedItems());
//    QMessageBox::StandardButton reply;
//    reply = QMessageBox::question(this,"Thông báo",QString("Bạn có muốn xoá số: %1").arg(n),
//    QMessageBox::Yes | QMessageBox::No);
//    if(reply == QMessageBox::Yes)
//    {
//        delete item;
//        QMessageBox::information(this,"Thông báo",QString("Đã xoá số: %1").arg(n));
//    }
//    else{}
}


void MainWindow::on_Button5_clicked() //xoá phần tử đầu
{
    QListWidgetItem *item = nullptr;
    item=ui->listWidget->item(0);
    int n=ui->listWidget->item(0)->text().toInt();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Thông báo",QString("Bạn có muốn xoá số: %1").arg(n),
    QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        delete item;
        QMessageBox::information(this,"Thông báo",QString("Đã xoá số: %1").arg(n));
    }
    else{}
}


void MainWindow::on_Button6_clicked() //xoá phần tử cuối
{
    QListWidgetItem *item = nullptr;
    int length = ui->listWidget->count();
    item=ui->listWidget->item(length-1);
    int n=ui->listWidget->item(length-1)->text().toInt();
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Thông báo",QString("Bạn có muốn xoá số: %1").arg(n),
    QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes)
    {
        delete item;
        QMessageBox::information(this,"Thông báo",QString("Đã xoá số: %1").arg(n));
    }
    else{}
}




