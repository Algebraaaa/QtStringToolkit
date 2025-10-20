#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox1->addItem("学生姓名,男,2003-6-15,汉族,山东","test_section");
    //ui->comboBox1->addItem("E:\\Project\\Qtemp\\samp4_02\\main.cpp");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showBoolInfo(QString str, bool CheckValue)
{
    if(CheckValue)
        ui->plainTextEdit->appendPlainText(str+"=true");
    else
        ui->plainTextEdit->appendPlainText(str+"=false");
}

void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}


void Widget::on_btnSection_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===setion()函数测试");
    int index = ui->comboBox1->findData("test_section");
    QString text = ui->comboBox1->itemText(index);
    ui->comboBox1->setCurrentIndex(index);
    QString str1=ui->comboBox1->currentText();
    ui->comboBox2->setCurrentIndex(1);
    QString str2=ui->comboBox2->currentText();
    int N=ui->spinBox->value();
    QString str3=str1.section(str2,N,N);
    ui->plainTextEdit->appendPlainText(str3);
}


void Widget::on_btnFrontAndBack_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===front()，back()函数测试");
    QString str1=ui->comboBox1->currentText();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    ui->plainTextEdit->appendPlainText("str1.font()="+QString(str1.front()));
    ui->plainTextEdit->appendPlainText("str1.back()="+QString(str1.back()));
}


void Widget::on_btnLetAndRight_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===left()，right()函数测试");
    QString str1=ui->comboBox1->currentText();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    ui->plainTextEdit->appendPlainText("str1.left(2)="+QString(str1.left(2)));
    ui->plainTextEdit->appendPlainText("str1.right(2)="+QString(str1.right(2)));
}


void Widget::on_btnFirstAndLast_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===first(),last()函数测试");
    QString str1=ui->comboBox1->currentText();
    QString str2=ui->comboBox2->currentText();
    ui->plainTextEdit->appendPlainText("str1= "+str1);
    ui->plainTextEdit->appendPlainText("str2= "+str2);

    int N=str1.lastIndexOf(str2);
    QString str3=str1.first(N+1);
    ui->plainTextEdit->appendPlainText(str3);
    str3=str1.last(str1.size()-N-1);
    ui->plainTextEdit->appendPlainText(str3);
}


void Widget::on_btnisNullAndEmpty_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===isNull()函数测试");
    QString str1,str2="";
    ui->plainTextEdit->appendPlainText("QString str1,str2=\"\"");
    showBoolInfo("str1.isNull()",str1.isNull());
    showBoolInfo("str1.isEmpty()",str1.isEmpty());
    showBoolInfo("\nstr2.isNull()",str2.isNull());
    showBoolInfo("str2.isEmpty()",str2.isEmpty());
    str2.clear();
    ui->plainTextEdit->appendPlainText("\nstr2.clear()后");
    showBoolInfo("\nstr2.isNull()",str2.isNull());
    showBoolInfo("str2.isEmpty()",str2.isEmpty());
}


void Widget::on_btnResize_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===resize()函数测试");
    QString str1;
    ui->plainTextEdit->appendPlainText("str1="+str1);
    str1.resize(6,'6');
    ui->plainTextEdit->appendPlainText("str1.resize(6,'6')后");
    ui->plainTextEdit->appendPlainText("str1="+str1);
}


void Widget::on_btnSizeAndLength_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===size(),length()函数测试");
    QString str1=ui->comboBox1->currentText();
    QString str2=ui->comboBox2->currentText();
    int N=str1.count(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中出现的次数为："+QString::number(N));
    N=str1.length();
    ui->plainTextEdit->appendPlainText("str1.length()="+QString::number(str1.length()));
    ui->plainTextEdit->appendPlainText("str1.size()="+QString::number(str1.size()));
}


void Widget::on_btnFill_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===fill()函数测试");
    QString str1=ui->comboBox1->currentText();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    str1.fill('X');
    ui->plainTextEdit->appendPlainText("执行完str1.fill('X');后："+str1);
    str1.fill(QChar(0x54C8),3);
    ui->plainTextEdit->appendPlainText("执行完str1.fill(QChar(0x54C8),3);后："+str1);
}


void Widget::on_btnIndexOf_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===IndexOf()函数测试");
    QString str1=ui->comboBox1->currentText();
    QString str2=ui->comboBox2->currentText();
    int N=str1.indexOf(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中首次出现的位置是："+QString::number(N));
    N=str1.lastIndexOf(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中最后出现的位置是："+QString::number(N));
}


void Widget::on_btnContains_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===contains()函数测试");
    QString str1=ui->comboBox1->currentText();
    QString str2=ui->comboBox2->currentText();
    bool N=str1.contains(str2);
    showBoolInfo("str1.contains(str2)",N);
    N=str1.contains(str2,Qt::CaseInsensitive);
    showBoolInfo("str1.contains(str2,Qt::CaseInsensitive)",N);
}


void Widget::on_btnEndsWith_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===endsWith(),startsWith()函数测试");
    QString str1=ui->comboBox1->currentText();
    QString str2=ui->comboBox2->currentText();
    bool N=str1.endsWith(str2);
    showBoolInfo("str1.endsWith(str2)",N);
    N=str1.startsWith(str2,Qt::CaseInsensitive);
    showBoolInfo("str1.startsWith(str2,Qt::CaseInsensitive)",N);
}


void Widget::on_btnCount_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===count()函数测试");
    QString str1=ui->comboBox1->currentText();
    QString str2=ui->comboBox2->currentText();
    int N=str1.count(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中出现的次数为："+QString::number(N));
}


void Widget::on_btnTrimmed_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===trimmed()函数测试");
    QString str1=ui->comboBox1->currentText();
    ui->plainTextEdit->appendPlainText("未执行时str1=\n"+str1);
    QString str2=str1.trimmed();
    ui->plainTextEdit->appendPlainText("执行str1.trimmed()后：\n"+str2);
    str2=str1.simplified();
    ui->plainTextEdit->appendPlainText("执行str1.simplified()后：\n"+str2);
}


void Widget::on_btnInsert_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===Insert()函数测试");
    QString str1="It is great!";
    ui->plainTextEdit->appendPlainText(str1);
    int N=str1.lastIndexOf(" ");
    str1.insert(N,"n't");
    ui->plainTextEdit->appendPlainText(str1);
}


void Widget::on_btnRemove_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===remove()函数测试");
    QString str1=ui->comboBox1->currentText();
    QString str2=ui->comboBox2->currentText();
    int N=str1.lastIndexOf(str2);
    str1.remove(N,20);
    ui->plainTextEdit->appendPlainText(str1);

    str1.remove(str2);
    ui->plainTextEdit->appendPlainText(str1);
}


void Widget::on_btnReplace_clicked()
{
    ui->plainTextEdit->appendPlainText("\n===replace()函数测试");
    QString str1="It is great";
    int N=str1.lastIndexOf(" ");
    QString subStr="wonderful";
    str1.replace(N+1,subStr.size(),subStr);
    ui->plainTextEdit->appendPlainText(str1);
}

