#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "thoat.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int value;
    void vietketqua(int result);
    int kiemtrachanle(int s);
//    int numselected =0;
protected:

    //    void closeEvent(QCloseEvent *event);

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    void on_Button_close_clicked();

    void on_Botton_nhap_clicked();

    void on_Botton_reset_clicked();

    void on_Button1_clicked();

    void on_Button2_clicked();

    void on_Button3_clicked();

    void on_Button4_clicked();

    void on_Button5_clicked();

    void on_Button6_clicked();

    void on_lineEdit_returnPressed();

private:

    Ui::MainWindow *ui;
    Thoat *thoat;
};
#endif // MAINWINDOW_H
