#include "widget.h"
#include "ui_widget.h"

// 构造函数：初始化 UI 界面并设置下拉框内容
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);    // 绑定 UI 设计文件
    iniComboBoxes();      // 初始化下拉框内容
}

// 析构函数：释放 ui 对象
Widget::~Widget()
{
    delete ui;
}

// 获取 comboBox1 当前选中的文本
QString Widget::getSelectedString01() const
{
    return ui->comboBox1->currentText();
}

// 获取 comboBox2 当前选中的文本
QString Widget::getSelectedString02() const
{
    return ui->comboBox2->currentText();
}

// 在 plainTextEdit 中追加测试标题，方便区分不同功能测试
void Widget::appendTestTitle(const QString &title)
{
    ui->plainTextEdit->appendPlainText("\n==="+title+"函数测试");
}

// 初始化下拉框内容
void Widget::iniComboBoxes()
{
    ui->comboBox1->addItem("E:\\Project\\Qtemp\\samp4_02\\main.cpp");
    ui->comboBox1->addItem("学生姓名,男,2003-6-15,汉族,山东","test_section");
    ui->comboBox1->addItem("  Are    you    OK?");
    ui->comboBox2->addItem("\\","test_01");
    ui->comboBox2->addItem(",","test_02");
}

// 显示布尔值测试结果（true/false）
void Widget::showBoolInfo(QString str, bool CheckValue)
{
    if(CheckValue)
        ui->plainTextEdit->appendPlainText(str+"=true");
    else
        ui->plainTextEdit->appendPlainText(str+"=false");
}

// 清空输出窗口内容
void Widget::on_btnClear_clicked()
{
    ui->plainTextEdit->clear();
}

// section() 函数测试：截取字符串的指定段落
void Widget::on_btnSection_clicked()
{
    appendTestTitle("section()");
    static bool isFirstTime=true; // 仅首次点击执行分段测试
    if(isFirstTime)
    {
        // 通过 data 查找并设置 comboBox 选项
        int index01 = ui->comboBox1->findData("test_section");
        if(index01!=-1)
            ui->comboBox1->setCurrentIndex(index01);
        int index02=ui->comboBox2->findData("test_02");
        if(index02!=-1)
            ui->comboBox2->setCurrentIndex(index02);

        // 获取字符串和分隔符
        QString str1=getSelectedString01();
        QString str2=getSelectedString02();

        // 按分隔符切割字符串
        QStringList parts=str1.split(str2);
        for(int i=0;i<parts.size();++i)
        {
            ui->plainTextEdit->appendPlainText(QString("[%1]%2").arg(i).arg(parts[i]));
        }
        isFirstTime=false;
        return;
    }

    // 非首次点击时使用 section 提取指定段落
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    int N=ui->spinBox->value();
    QString str3=str1.section(str2,N,N);
    ui->plainTextEdit->appendPlainText(QString("[%1]%2").arg(N).arg(str3));
}

// front() 与 back() 函数测试：获取字符串首尾字符
void Widget::on_btnFrontAndBack_clicked()
{
    appendTestTitle("front()，back()");
    QString str1=getSelectedString01();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    ui->plainTextEdit->appendPlainText("str1.front()="+QString(str1.front()));
    ui->plainTextEdit->appendPlainText("str1.back()="+QString(str1.back()));
}

// left() 与 right() 函数测试：获取左/右子串
void Widget::on_btnLetAndRight_clicked()
{
    appendTestTitle("left()，right()");
    QString str1=getSelectedString01();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    ui->plainTextEdit->appendPlainText("str1.left(2)="+QString(str1.left(2)));
    ui->plainTextEdit->appendPlainText("str1.right(2)="+QString(str1.right(2)));
}

// first() 与 last() 函数测试：提取前 N 个和后 N 个字符
void Widget::on_btnFirstAndLast_clicked()
{
    appendTestTitle("first(),last()");
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    ui->plainTextEdit->appendPlainText("str1= "+str1);
    ui->plainTextEdit->appendPlainText("str2= "+str2);

    int N=str1.lastIndexOf(str2);
    QString str3=str1.first(N+1);                // 从头取到匹配位置
    ui->plainTextEdit->appendPlainText(str3);
    str3=str1.last(str1.size()-N-1);             // 取匹配之后的部分
    ui->plainTextEdit->appendPlainText(str3);
}

// isNull() 与 isEmpty() 测试：判断字符串是否为空或未初始化
void Widget::on_btnisNullAndEmpty_clicked()
{
    appendTestTitle("isNull()");
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

// resize() 函数测试：调整字符串长度并填充指定字符
void Widget::on_btnResize_clicked()
{
    appendTestTitle("resize()");
    QString str1;
    ui->plainTextEdit->appendPlainText("str1="+str1);
    str1.resize(6,'6');
    ui->plainTextEdit->appendPlainText("str1.resize(6,'6')后");
    ui->plainTextEdit->appendPlainText("str1="+str1);
}

// size() 与 length() 测试：统计字符串长度及子串出现次数
void Widget::on_btnSizeAndLength_clicked()
{
    appendTestTitle("size(),length()");
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    int N=str1.count(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中出现的次数为："+QString::number(N));
    ui->plainTextEdit->appendPlainText("str1.length()="+QString::number(str1.length()));
    ui->plainTextEdit->appendPlainText("str1.size()="+QString::number(str1.size()));
}

// fill() 函数测试：用指定字符填充整个字符串
void Widget::on_btnFill_clicked()
{
    appendTestTitle("fill()");
    QString str1=getSelectedString01();
    ui->plainTextEdit->appendPlainText("str1="+str1);
    str1.fill('X');
    ui->plainTextEdit->appendPlainText("执行完str1.fill('X');后："+str1);
    str1.fill(QChar(0x54C8),3); // 用“哈”字填充三次
    ui->plainTextEdit->appendPlainText("执行完str1.fill(QChar(0x54C8),3);后："+str1);
}

// indexOf() 函数测试：查找子串出现的位置
void Widget::on_btnIndexOf_clicked()
{
    appendTestTitle("IndexOf()");
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    int N=str1.indexOf(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中首次出现的位置是："+QString::number(N));
    N=str1.lastIndexOf(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中最后出现的位置是："+QString::number(N));
}

// contains() 函数测试：判断字符串是否包含某子串
void Widget::on_btnContains_clicked()
{
    appendTestTitle("contains()");
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    bool N=str1.contains(str2);
    showBoolInfo("str1.contains(str2)",N);
    N=str1.contains(str2,Qt::CaseInsensitive); // 忽略大小写
    showBoolInfo("str1.contains(str2,Qt::CaseInsensitive)",N);
}

// startsWith() 与 endsWith() 测试：判断字符串是否以指定内容开头/结尾
void Widget::on_btnEndsWith_clicked()
{
    appendTestTitle("endsWith(),startsWith()");
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    bool N=str1.endsWith(str2);
    showBoolInfo("str1.endsWith(str2)",N);
    N=str1.startsWith(str2,Qt::CaseInsensitive);
    showBoolInfo("str1.startsWith(str2,Qt::CaseInsensitive)",N);
}

// count() 函数测试：统计子串出现次数
void Widget::on_btnCount_clicked()
{
    appendTestTitle("count()");
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    int N=str1.count(str2);
    ui->plainTextEdit->appendPlainText("str2在str1中出现的次数为："+QString::number(N));
}

// trimmed() 与 simplified() 函数测试：去除空格与多余空白
void Widget::on_btnTrimmed_clicked()
{
    appendTestTitle("trimmed()");
    QString str1=getSelectedString01();
    ui->plainTextEdit->appendPlainText("未执行时str1=\n"+str1);
    QString str2=str1.trimmed();
    ui->plainTextEdit->appendPlainText("执行str1.trimmed()后：\n"+str2);
    str2=str1.simplified();
    ui->plainTextEdit->appendPlainText("执行str1.simplified()后：\n"+str2);
}

// insert() 函数测试：在字符串中插入子串
void Widget::on_btnInsert_clicked()
{
    appendTestTitle("Insert()");
    QString str1="It is great!";
    ui->plainTextEdit->appendPlainText(str1);
    int N=str1.lastIndexOf(" ");
    str1.insert(N,"n't"); // 在最后一个空格处插入“n't”
    ui->plainTextEdit->appendPlainText(str1);
}

// remove() 函数测试：删除指定位置或子串
void Widget::on_btnRemove_clicked()
{
    appendTestTitle("remove()");
    QString str1=getSelectedString01();
    QString str2=getSelectedString02();
    int N=str1.lastIndexOf(str2);
    str1.remove(N,20); // 从找到的位置起删除20个字符
    ui->plainTextEdit->appendPlainText(str1);

    str1.remove(str2); // 删除所有匹配的子串
    ui->plainTextEdit->appendPlainText(str1);
}

// replace() 函数测试：替换字符串指定部分内容
void Widget::on_btnReplace_clicked()
{
    appendTestTitle("replace()");
    QString str1="It is great";
    int N=str1.lastIndexOf(" ");
    ui->plainTextEdit->appendPlainText(str1);
    QString subStr="wonderful";
    str1.replace(N+1,subStr.size(),subStr); // 替换最后一个单词
    ui->plainTextEdit->appendPlainText(str1);
}
