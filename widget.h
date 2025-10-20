#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {class Widget;}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_btnClear_clicked();

    void on_btnSection_clicked();

    void on_btnFrontAndBack_clicked();

    void on_btnLetAndRight_clicked();

    void on_btnFirstAndLast_clicked();

    void on_btnisNullAndEmpty_clicked();

    void on_btnResize_clicked();

    void on_btnSizeAndLength_clicked();

    void on_btnFill_clicked();

    void on_btnIndexOf_clicked();

    void on_btnContains_clicked();

    void on_btnEndsWith_clicked();

    void on_btnCount_clicked();

    void on_btnTrimmed_clicked();

    void on_btnInsert_clicked();

    void on_btnRemove_clicked();

    void on_btnReplace_clicked();

private:
    void showBoolInfo(QString str,bool CheckValue);
    Ui::Widget *ui;
};
#endif // WIDGET_H
