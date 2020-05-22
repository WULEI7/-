#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include "qvalidator.h"
#include "qstring.h"
#include "loan.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon.ico"));//设置窗口图标
    this->setWindowTitle("房贷计算器");//设置窗口标题
    this->setObjectName("mainWindow");
    this->setStyleSheet("#mainWindow{border-image:url(:/background.jpg);}");//设置背景图片

    //此处初始化界面布局（下拉框均未改动时的初始界面）
    ui->lineEdit_Q0->setVisible(1);
    ui->lineEdit_Q00->setVisible(1);
    ui->lineEdit_Q000->setVisible(1);
    ui->lineEdit_Q1A->setVisible(1);
    ui->lineEdit_Q2A->setVisible(1);
    ui->lineEdit_Q3A->setVisible(1);
    ui->lineEdit_Q3B->setVisible(0);
    ui->lineEdit_Q4AB->setVisible(1);
    ui->lineEdit_Q5AB->setVisible(1);
    ui->lineEdit_1A->setVisible(1);
    ui->lineEdit_2A->setVisible(1);
    ui->lineEdit_3A->setVisible(1);
    ui->lineEdit_3B->setVisible(0);
    ui->lineEdit_4AB->setVisible(1);
    ui->lineEdit_5AB->setVisible(1);
    ui->lineEdit_Q1C->setVisible(0);
    ui->lineEdit_Q2C->setVisible(0);
    ui->lineEdit_Q3C->setVisible(0);
    ui->lineEdit_Q4C->setVisible(0);
    ui->lineEdit_Q5C->setVisible(0);
    ui->lineEdit_1C->setVisible(0);
    ui->lineEdit_2C->setVisible(0);
    ui->lineEdit_3C->setVisible(0);
    ui->lineEdit_4C->setVisible(0);
    ui->lineEdit_5C->setVisible(0);
    ui->comboBox_1->setFocus();//此句作用是取消默认光标闪烁

    //此处限制输入框只能输入数字，并限制小数位数
    QValidator *v1A=new QDoubleValidator(0.01,1000000.00,2,this);
    ui->lineEdit_1A->setValidator(v1A);//根据面积单价计算：房屋单价
    QValidator *v2A=new QDoubleValidator(0.01,1000.00,2,this);
    ui->lineEdit_2A->setValidator(v2A);//根据面积单价计算：房屋面积
    QValidator *v3A=new QDoubleValidator(0.1,10.0,1,this);
    ui->lineEdit_3A->setValidator(v3A);//根据面积单价计算：贷款成数
    QValidator *v3B=new QDoubleValidator(0.01,10000.00,2,this);
    ui->lineEdit_3B->setValidator(v3B);//根据贷款总额计算：贷款总额
    QValidator *v4AB=new QIntValidator(1,30,this);
    ui->lineEdit_4AB->setValidator(v4AB);//根据面积单价计算、根据贷款总额计算：贷款年数
    QValidator *v5AB=new QDoubleValidator(0.01,100.00,2,this);
    ui->lineEdit_5AB->setValidator(v5AB);//根据面积单价计算、根据贷款总额计算：贷款利率
    QValidator *v1C=new QDoubleValidator(0.01,10000.00,2,this);
    ui->lineEdit_1C->setValidator(v1C);//组合贷款：商业贷款总额
    QValidator *v2C=new QDoubleValidator(0.01,100.00,2,this);
    ui->lineEdit_2C->setValidator(v2C);//组合贷款：商业贷款利率
    QValidator *v3C=new QDoubleValidator(0.01,10000.00,2,this);
    ui->lineEdit_3C->setValidator(v3C);//组合贷款：公积金贷款总额
    QValidator *v4C=new QDoubleValidator(0.01,100.00,2,this);
    ui->lineEdit_4C->setValidator(v4C);//组合贷款：公积金贷款利率
    QValidator *v5C=new QIntValidator(1,30,this);
    ui->lineEdit_5C->setValidator(v5C);//组合贷款：贷款年数
    //本程序因只需实现较简单的限制输入功能，没有使用正则表达式，使用的是QValidator
    //后面开始计算前还会对用户输入数字大小是否合理进行判断并给出提示，为程序正常运行增加保险
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_1_activated(int index)//三种贷款方式选择
{
    if(index==0)//选择商业贷款
    {
        if(ui->comboBox_2->currentIndex()==0)//如果之前选中根据单价面积计算
        {
            ui->comboBox_2->setVisible(1);
            ui->lineEdit_Q0->setVisible(1);
            ui->lineEdit_Q00->setVisible(1);
            ui->lineEdit_Q000->setVisible(1);
            ui->lineEdit_Q1A->setVisible(1);
            ui->lineEdit_Q2A->setVisible(1);
            ui->lineEdit_Q3A->setVisible(1);
            ui->lineEdit_Q3B->setVisible(0);
            ui->lineEdit_Q4AB->setVisible(1);
            ui->lineEdit_Q5AB->setVisible(1);
            ui->lineEdit_1A->setVisible(1);
            ui->lineEdit_2A->setVisible(1);
            ui->lineEdit_3A->setVisible(1);
            ui->lineEdit_3B->setVisible(0);
            ui->lineEdit_4AB->setVisible(1);
            ui->lineEdit_5AB->setVisible(1);
            ui->lineEdit_Q1C->setVisible(0);
            ui->lineEdit_Q2C->setVisible(0);
            ui->lineEdit_Q3C->setVisible(0);
            ui->lineEdit_Q4C->setVisible(0);
            ui->lineEdit_Q5C->setVisible(0);
            ui->lineEdit_1C->setVisible(0);
            ui->lineEdit_2C->setVisible(0);
            ui->lineEdit_3C->setVisible(0);
            ui->lineEdit_4C->setVisible(0);
            ui->lineEdit_5C->setVisible(0);
        }
        else if(ui->comboBox_2->currentIndex()==1)//如果之前选中根据贷款总额计算
        {
            ui->comboBox_2->setVisible(1);
            ui->lineEdit_Q0->setVisible(1);
            ui->lineEdit_Q00->setVisible(1);
            ui->lineEdit_Q000->setVisible(1);
            ui->lineEdit_Q1A->setVisible(0);
            ui->lineEdit_Q2A->setVisible(0);
            ui->lineEdit_Q3A->setVisible(0);
            ui->lineEdit_Q3B->setVisible(1);
            ui->lineEdit_Q4AB->setVisible(1);
            ui->lineEdit_Q5AB->setVisible(1);
            ui->lineEdit_1A->setVisible(0);
            ui->lineEdit_2A->setVisible(0);
            ui->lineEdit_3A->setVisible(0);
            ui->lineEdit_3B->setVisible(1);
            ui->lineEdit_4AB->setVisible(1);
            ui->lineEdit_5AB->setVisible(1);
            ui->lineEdit_Q1C->setVisible(0);
            ui->lineEdit_Q2C->setVisible(0);
            ui->lineEdit_Q3C->setVisible(0);
            ui->lineEdit_Q4C->setVisible(0);
            ui->lineEdit_Q5C->setVisible(0);
            ui->lineEdit_1C->setVisible(0);
            ui->lineEdit_2C->setVisible(0);
            ui->lineEdit_3C->setVisible(0);
            ui->lineEdit_4C->setVisible(0);
            ui->lineEdit_5C->setVisible(0);
        }
    }
    else if(index==1)//选择公积金贷款
    {
        if(ui->comboBox_2->currentIndex()==0)//如果之前选中根据单价面积计算
        {
            ui->comboBox_2->setVisible(1);
            ui->lineEdit_Q0->setVisible(1);
            ui->lineEdit_Q00->setVisible(1);
            ui->lineEdit_Q000->setVisible(1);
            ui->lineEdit_Q1A->setVisible(1);
            ui->lineEdit_Q2A->setVisible(1);
            ui->lineEdit_Q3A->setVisible(1);
            ui->lineEdit_Q3B->setVisible(0);
            ui->lineEdit_Q4AB->setVisible(1);
            ui->lineEdit_Q5AB->setVisible(1);
            ui->lineEdit_1A->setVisible(1);
            ui->lineEdit_2A->setVisible(1);
            ui->lineEdit_3A->setVisible(1);
            ui->lineEdit_3B->setVisible(0);
            ui->lineEdit_4AB->setVisible(1);
            ui->lineEdit_5AB->setVisible(1);
            ui->lineEdit_Q1C->setVisible(0);
            ui->lineEdit_Q2C->setVisible(0);
            ui->lineEdit_Q3C->setVisible(0);
            ui->lineEdit_Q4C->setVisible(0);
            ui->lineEdit_Q5C->setVisible(0);
            ui->lineEdit_1C->setVisible(0);
            ui->lineEdit_2C->setVisible(0);
            ui->lineEdit_3C->setVisible(0);
            ui->lineEdit_4C->setVisible(0);
            ui->lineEdit_5C->setVisible(0);
        }
        else if(ui->comboBox_2->currentIndex()==1)//如果之前选中根据贷款总额计算
        {
            ui->comboBox_2->setVisible(1);
            ui->lineEdit_Q0->setVisible(1);
            ui->lineEdit_Q00->setVisible(1);
            ui->lineEdit_Q000->setVisible(1);
            ui->lineEdit_Q1A->setVisible(0);
            ui->lineEdit_Q2A->setVisible(0);
            ui->lineEdit_Q3A->setVisible(0);
            ui->lineEdit_Q3B->setVisible(1);
            ui->lineEdit_Q4AB->setVisible(1);
            ui->lineEdit_Q5AB->setVisible(1);
            ui->lineEdit_1A->setVisible(0);
            ui->lineEdit_2A->setVisible(0);
            ui->lineEdit_3A->setVisible(0);
            ui->lineEdit_3B->setVisible(1);
            ui->lineEdit_4AB->setVisible(1);
            ui->lineEdit_5AB->setVisible(1);
            ui->lineEdit_Q1C->setVisible(0);
            ui->lineEdit_Q2C->setVisible(0);
            ui->lineEdit_Q3C->setVisible(0);
            ui->lineEdit_Q4C->setVisible(0);
            ui->lineEdit_Q5C->setVisible(0);
            ui->lineEdit_1C->setVisible(0);
            ui->lineEdit_2C->setVisible(0);
            ui->lineEdit_3C->setVisible(0);
            ui->lineEdit_4C->setVisible(0);
            ui->lineEdit_5C->setVisible(0);
        }
    }
    else if(index==2)//选择组合贷款
    {
        ui->comboBox_2->setVisible(0);
        ui->lineEdit_Q0->setVisible(1);
        ui->lineEdit_Q00->setVisible(0);
        ui->lineEdit_Q000->setVisible(1);
        ui->lineEdit_Q1A->setVisible(0);
        ui->lineEdit_Q2A->setVisible(0);
        ui->lineEdit_Q3A->setVisible(0);
        ui->lineEdit_Q3B->setVisible(0);
        ui->lineEdit_Q4AB->setVisible(0);
        ui->lineEdit_Q5AB->setVisible(0);
        ui->lineEdit_1A->setVisible(0);
        ui->lineEdit_2A->setVisible(0);
        ui->lineEdit_3A->setVisible(0);
        ui->lineEdit_3B->setVisible(0);
        ui->lineEdit_4AB->setVisible(0);
        ui->lineEdit_5AB->setVisible(0);
        ui->lineEdit_Q1C->setVisible(1);
        ui->lineEdit_Q2C->setVisible(1);
        ui->lineEdit_Q3C->setVisible(1);
        ui->lineEdit_Q4C->setVisible(1);
        ui->lineEdit_Q5C->setVisible(1);
        ui->lineEdit_1C->setVisible(1);
        ui->lineEdit_2C->setVisible(1);
        ui->lineEdit_3C->setVisible(1);
        ui->lineEdit_4C->setVisible(1);
        ui->lineEdit_5C->setVisible(1);
    }
}

void MainWindow::on_comboBox_2_activated(int index)//选择根据面积单价或贷款总额计算
{
    if(index==0)//选择根据面积单价计算
    {
        ui->lineEdit_Q1A->setVisible(1);
        ui->lineEdit_Q2A->setVisible(1);
        ui->lineEdit_Q3A->setVisible(1);
        ui->lineEdit_Q3B->setVisible(0);
        ui->lineEdit_Q4AB->setVisible(1);
        ui->lineEdit_Q5AB->setVisible(1);
        ui->lineEdit_1A->setVisible(1);
        ui->lineEdit_2A->setVisible(1);
        ui->lineEdit_3A->setVisible(1);
        ui->lineEdit_3B->setVisible(0);
        ui->lineEdit_4AB->setVisible(1);
        ui->lineEdit_5AB->setVisible(1);
    }
    else if(index==1)//选择根据贷款总额计算
    {
        ui->lineEdit_Q1A->setVisible(0);
        ui->lineEdit_Q2A->setVisible(0);
        ui->lineEdit_Q3A->setVisible(0);
        ui->lineEdit_Q3B->setVisible(1);
        ui->lineEdit_Q4AB->setVisible(1);
        ui->lineEdit_Q5AB->setVisible(1);
        ui->lineEdit_1A->setVisible(0);
        ui->lineEdit_2A->setVisible(0);
        ui->lineEdit_3A->setVisible(0);
        ui->lineEdit_3B->setVisible(1);
        ui->lineEdit_4AB->setVisible(1);
        ui->lineEdit_5AB->setVisible(1);
    }
}

void MainWindow::on_pushButton_1_clicked()//清空重填，弹窗提示用户是否清空
{
    QMessageBox::StandardButton reply;
    reply=QMessageBox::information(this,"清空数据提示","您确定要清空重填吗？",QMessageBox::No,QMessageBox::Yes);//光标默认选择No
    if(reply==QMessageBox::Yes)
    {
        ui->lineEdit_1A->clear();
        ui->lineEdit_2A->clear();
        ui->lineEdit_3A->clear();
        ui->lineEdit_3B->clear();
        ui->lineEdit_4AB->clear();
        ui->lineEdit_5AB->clear();
        ui->lineEdit_1C->clear();
        ui->lineEdit_2C->clear();
        ui->lineEdit_3C->clear();
        ui->lineEdit_4C->clear();
        ui->lineEdit_5C->clear();
        ui->textEdit_result->clear();
    }
}

void MainWindow::on_pushButton_2_clicked()//开始计算
{
    ui->textEdit_result->clear();//清空上次计算结果
//----------------------------------------------------------------------------------------------------------------------------------------
    if(ui->comboBox_1->currentIndex()==0)//选择商业贷款
    {
        if(ui->comboBox_2->currentIndex()==0)//选择根据单价面积计算
        {
            double input1;//单价
            double input2;//面积
            double input3;//成数
            int input4;//年数
            double input5;//利率
            bool isOK_1,isOK_2,isOK_3,isOK_4,isOK_5;
            input1=ui->lineEdit_1A->text().toDouble(&isOK_1);
            input2=ui->lineEdit_2A->text().toDouble(&isOK_2);
            input3=ui->lineEdit_3A->text().toDouble(&isOK_3);
            input4=ui->lineEdit_4AB->text().toInt(&isOK_4);
            input5=ui->lineEdit_5AB->text().toDouble(&isOK_5);
            if(isOK_1==0||input1<=0||input1>1000000)
            {
                QMessageBox::warning(this,"非法输入提示","房屋单价只能是不超过1000000的正数哦，请重新输入！");
            }
            else if(isOK_2==0||input2<=0||input2>1000)
            {
                QMessageBox::warning(this,"非法输入提示","房屋面积只能是不超过1000的正数哦，请重新输入！");
            }
            else if(isOK_3==0||input3<=0||input3>10)
            {
                QMessageBox::warning(this,"非法输入提示","贷款成数只能是不超过10的正数哦，请重新输入！");
            }
            else if(isOK_4==0||input4<=0||input4>30)
            {
                QMessageBox::warning(this,"非法输入提示","贷款年数只能是1-30之间的正整数哦，请重新输入！");
            }
            else if(isOK_5==0||input5<=0||input5>100)
            {
                QMessageBox::warning(this,"非法输入提示","贷款利率只能是不超过100的正数哦，请重新输入！");
            }
            //开始计算前，判断用户输入数字大小合理性并给出提示，给程序正常运行增加保险
            else
            {
                ui->textEdit_result->clear();
                CommerLoan a;//商业贷款
                a.setCommerTotal(input1*input2/100000*input3);
                a.setCommerMonth(input4);
                a.setCommerRate(input5);
                if(ui->comboBox_3->currentIndex()==0)//商业贷款，根据单价面积计算，等额本息
                {
                    QString result="";
                    result+="您选择的是商业贷款，等额本息，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getCommerTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getCommerInterestX(),'f',2);
                    result+="万元\n参考月供：";
                    result+=QString::number(a.getCommerMonthpay(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getCommerMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
                else if(ui->comboBox_3->currentIndex()==1)//商业贷款，根据单价面积计算，等额本金
                {
                    QString result="";
                    result+="您选择的是商业贷款，等额本金，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getCommerTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getCommerInterestY(),'f',2);
                    result+="万元\n首月月供：";
                    result+=QString::number(a.getCommerFirstmonth(),'f',2);
                    result+="元\n每月递减：";
                    result+=QString::number(a.getCommerMonthdec(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getCommerMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
            }
        }
        else if(ui->comboBox_2->currentIndex()==1)//选择根据贷款总额计算
        {
            double input1;//贷款总额
            int input2;//贷款年数
            double input3;//贷款利率
            bool isOK_1,isOK_2,isOK_3;
            input1=ui->lineEdit_3B->text().toDouble(&isOK_1);
            input2=ui->lineEdit_4AB->text().toInt(&isOK_2);
            input3=ui->lineEdit_5AB->text().toDouble(&isOK_3);
            if(isOK_1==0||input1<=0||input1>1000)
            {
                QMessageBox::warning(this,"非法输入提示","贷款总额只能是不超过10000的正数哦，请重新输入！");
            }
            else if(isOK_2==0||input2<=0||input2>30)
            {
                QMessageBox::warning(this,"非法输入提示","贷款年数只能是1-30之间的正整数哦，请重新输入！");
            }
            else if(isOK_3==0||input1<=0||input1>100)
            {
                QMessageBox::warning(this,"非法输入提示","贷款利率只能是不超过100的正数哦，请重新输入！");
            }
            else
            {
                ui->textEdit_result->clear();
                CommerLoan a;//商业贷款
                a.setCommerTotal(input1);
                a.setCommerMonth(input2);
                a.setCommerRate(input3);
                if(ui->comboBox_3->currentIndex()==0)//商业贷款，根据贷款总额计算，等额本息
                {
                    QString result="";
                    result+="您选择的是商业贷款，等额本息，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getCommerTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getCommerInterestX(),'f',2);
                    result+="万元\n参考月供：";
                    result+=QString::number(a.getCommerMonthpay(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getCommerMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
                else if(ui->comboBox_3->currentIndex()==1)//商业贷款，根据贷款总额计算，等额本金
                {
                    QString result="";
                    result+="您选择的是商业贷款，等额本金，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getCommerTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getCommerInterestY(),'f',2);
                    result+="万元\n首月月供：";
                    result+=QString::number(a.getCommerFirstmonth(),'f',2);
                    result+="元\n每月递减：";
                    result+=QString::number(a.getCommerMonthdec(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getCommerMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
            }
        }
    }
//----------------------------------------------------------------------------------------------------------------------------------------
    else if(ui->comboBox_1->currentIndex()==1)//选择公积金贷款
    {
        if(ui->comboBox_2->currentIndex()==0)//选择根据单价面积计算
        {
            double input1;//单价
            double input2;//面积
            double input3;//成数
            int input4;//年数
            double input5;//利率
            bool isOK_1,isOK_2,isOK_3,isOK_4,isOK_5;
            input1=ui->lineEdit_1A->text().toDouble(&isOK_1);
            input2=ui->lineEdit_2A->text().toDouble(&isOK_2);
            input3=ui->lineEdit_3A->text().toDouble(&isOK_3);
            input4=ui->lineEdit_4AB->text().toInt(&isOK_4);
            input5=ui->lineEdit_5AB->text().toDouble(&isOK_5);
            if(isOK_1==0||input1<=0||input1>1000000)
            {
                QMessageBox::warning(this,"非法输入提示","房屋单价只能是不超过1000000的正数哦，请重新输入！");
            }
            else if(isOK_2==0||input2<=0||input2>1000)
            {
                QMessageBox::warning(this,"非法输入提示","房屋面积只能是不超过1000的正数哦，请重新输入！");
            }
            else if(isOK_3==0||input3<=0||input3>10)
            {
                QMessageBox::warning(this,"非法输入提示","贷款成数只能是不超过10的正数哦，请重新输入！");
            }
            else if(isOK_4==0||input4<=0||input4>30)
            {
                QMessageBox::warning(this,"非法输入提示","贷款年数只能是1-30之间的正整数哦，请重新输入！");
            }
            else if(isOK_5==0||input5<=0||input5>100)
            {
                QMessageBox::warning(this,"非法输入提示","贷款利率只能是不超过100的正数哦，请重新输入！");
            }
            else
            {
                ui->textEdit_result->clear();
                AcfundLoan a;//公积金贷款
                a.setAcfundTotal(input1*input2/100000*input3);
                a.setAcfundMonth(input4);
                a.setAcfundRate(input5);
                if(ui->comboBox_3->currentIndex()==0)//公积金贷款，根据单价面积计算，等额本息
                {
                    QString result="";
                    result+="您选择的是公积金贷款，等额本息，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getAcfundTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getAcfundInterestX(),'f',2);
                    result+="万元\n参考月供：";
                    result+=QString::number(a.getAcfundMonthpay(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getAcfundMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
                else if(ui->comboBox_3->currentIndex()==1)//公积金贷款，根据单价面积计算，等额本金
                {
                    QString result="";
                    result+="您选择的是公积金贷款，等额本金，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getAcfundTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getAcfundInterestY(),'f',2);
                    result+="万元\n首月月供：";
                    result+=QString::number(a.getAcfundFirstmonth(),'f',2);
                    result+="元\n每月递减：";
                    result+=QString::number(a.getAcfundMonthdec(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getAcfundMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
            }
        }
        else if(ui->comboBox_2->currentIndex()==1)//选择根据贷款总额计算
        {
            double input1;//贷款总额
            int input2;//贷款年数
            double input3;//贷款利率
            bool isOK_1,isOK_2,isOK_3;
            input1=ui->lineEdit_3B->text().toDouble(&isOK_1);
            input2=ui->lineEdit_4AB->text().toInt(&isOK_2);
            input3=ui->lineEdit_5AB->text().toDouble(&isOK_3);
            if(isOK_1==0||input1<=0||input1>1000)
            {
                QMessageBox::warning(this,"非法输入提示","贷款总额只能是不超过10000的正数哦，请重新输入！");
            }
            else if(isOK_2==0||input2<=0||input2>30)
            {
                QMessageBox::warning(this,"非法输入提示","贷款年数只能是1-30之间的正整数哦，请重新输入！");
            }
            else if(isOK_3==0||input1<=0||input1>100)
            {
                QMessageBox::warning(this,"非法输入提示","贷款利率只能是不超过100的正数哦，请重新输入！");
            }
            else
            {
                ui->textEdit_result->clear();
                AcfundLoan a;//公积金贷款
                a.setAcfundTotal(input1);
                a.setAcfundMonth(input2);
                a.setAcfundRate(input3);
                if(ui->comboBox_3->currentIndex()==0)//公积金贷款，根据贷款总额计算，等额本息
                {
                    QString result="";
                    result+="您选择的是公积金贷款，等额本息，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getAcfundTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getAcfundInterestX(),'f',2);
                    result+="万元\n参考月供：";
                    result+=QString::number(a.getAcfundMonthpay(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getAcfundMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
                else if(ui->comboBox_3->currentIndex()==1)//公积金贷款，根据贷款总额计算，等额本金
                {
                    QString result="";
                    result+="您选择的是公积金贷款，等额本金，计算结果：\n";
                    result+="贷款总额：";
                    result+=QString::number(a.getAcfundTotal(),'f',2);
                    result+="万元\n支付利息：";
                    result+=QString::number(a.getAcfundInterestY(),'f',2);
                    result+="万元\n首月月供：";
                    result+=QString::number(a.getAcfundFirstmonth(),'f',2);
                    result+="元\n每月递减：";
                    result+=QString::number(a.getAcfundMonthdec(),'f',2);
                    result+="元\n还款月数：";
                    result+=QString::number(a.getAcfundMonth());
                    result+="个月\n";
                    ui->textEdit_result->insertPlainText(result);
                }
            }
        }
    }
//----------------------------------------------------------------------------------------------------------------------------------------
    else if(ui->comboBox_1->currentIndex()==2)//选择组合贷款
    {
        double input1;//商贷总额
        double input2;//商贷利率
        double input3;//公积金总额
        double input4;//公积金利率
        int input5;//贷款年数
        bool isOK_1,isOK_2,isOK_3,isOK_4,isOK_5;
        input1=ui->lineEdit_1C->text().toDouble(&isOK_1);
        input2=ui->lineEdit_2C->text().toDouble(&isOK_2);
        input3=ui->lineEdit_3C->text().toDouble(&isOK_3);
        input4=ui->lineEdit_4C->text().toDouble(&isOK_4);
        input5=ui->lineEdit_5C->text().toInt(&isOK_5);
        if(isOK_1==0||input1<=0||input1>1000)
        {
            QMessageBox::warning(this,"非法输入提示","商业贷款总额只能是不超过10000的正数哦，请重新输入！");
        }
        else if(isOK_2==0||input2<=0||input2>100)
        {
            QMessageBox::warning(this,"非法输入提示","商业贷款利率只能是不超过100的正数哦，请重新输入！");
        }
        else if(isOK_3==0||input3<=0||input3>1000)
        {
            QMessageBox::warning(this,"非法输入提示","公积金贷款总额只能是不超过10000的正数哦，请重新输入！");
        }
        else if(isOK_4==0||input4<=0||input4>100)
        {
            QMessageBox::warning(this,"非法输入提示","公积金贷款利率只能是不超过100的正数哦，请重新输入！");
        }
        else if(isOK_5==0||input5<=0||input5>30)
        {
            QMessageBox::warning(this,"非法输入提示","贷款年数只能是1-30之间的正整数哦，请重新输入！");
        }
        else
        {
            ui->textEdit_result->clear();
            CombinLoan a;//组合贷款
            a.setCommerTotal(input1);
            a.setCommerMonth(input5);
            a.setCommerRate(input2);
            a.setAcfundTotal(input3);
            a.setAcfundMonth(input5);
            a.setAcfundRate(input4);
            if(ui->comboBox_3->currentIndex()==0)//组合贷款，等额本息
            {
                QString result="";
                result+="您选择的是组合贷款，等额本息，计算结果：\n";
                result+="贷款总额：";
                result+=QString::number(a.getCombinTotal(),'f',2);
                result+="万元\n支付利息：";
                result+=QString::number(a.getCombinInterestX(),'f',2);
                result+="万元\n参考月供：";
                result+=QString::number(a.getCombinMonthpay(),'f',2);
                result+="元\n还款月数：";
                result+=QString::number(a.getCombinMonth());
                result+="个月\n";
                ui->textEdit_result->insertPlainText(result);
            }
            else if(ui->comboBox_3->currentIndex()==1)//组合贷款，等额本金
            {
                QString result="";
                result+="您选择的是组合贷款，等额本金，计算结果：\n";
                result+="贷款总额：";
                result+=QString::number(a.getCombinTotal(),'f',2);
                result+="万元\n支付利息：";
                result+=QString::number(a.getCombinInterestY(),'f',2);
                result+="万元\n首月月供：";
                result+=QString::number(a.getCombinFirstmonth(),'f',2);
                result+="元\n每月递减：";
                result+=QString::number(a.getCombinMonthdec(),'f',2);
                result+="元\n还款月数：";
                result+=QString::number(a.getCombinMonth());
                result+="个月\n";
                ui->textEdit_result->insertPlainText(result);
            }
        }
    }

}
