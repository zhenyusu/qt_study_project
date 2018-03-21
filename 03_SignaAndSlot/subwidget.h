#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>
class SubWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SubWidget(QWidget *parent = 0);
    void sendSlot();
private:
    QPushButton b3;

signals:
    /*信号必须有signals关键字来声明
     * 信号没有返回值，但是可以有参数
     * 信号就是函数的声明，只需要声明，无需定义
     * 使用:emit mySignal();
     * 信号可以重载

    */
    void mySignals();
    void mySignals(int,QString);

};

#endif // SUBWIDGET_H
