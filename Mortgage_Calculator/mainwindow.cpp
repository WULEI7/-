#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "loan.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    ui->lineEdit_1->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->textEdit_result->clear();
    double input1,input3;
    int input2;
    input1=ui->lineEdit_1->text().toDouble();
    input2=ui->lineEdit_2->text().toInt();
    input3=ui->lineEdit_3->text().toDouble();
    AcfundLoan a;
    a.setAcfundTotal(input1);
    a.setAcfundMonth(input2);
    a.setAcfundRate(input3);
    QString result="";
    result+="计算结果：\n";
    result+="贷款总额：";
    result+=QString::number(a.getAcfundTotal());
    result+="万元\n支付利息：";
    result+=QString::number(a.getAcfundInterestX());
    result+="万元\n参考月供：";
    result+=QString::number(a.getAcfundMonthpay());
    result+="元\n利率：";
    result+=QString::number(a.getAcfundRate());
    result+="%\n";
    ui->textEdit_result->insertPlainText(result);
}
