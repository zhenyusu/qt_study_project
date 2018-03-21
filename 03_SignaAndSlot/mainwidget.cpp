#include "mainwidget.h"
#include <QPushButton>
#include "subwidget.h"
#include <QDebug>
//解决乱码问题
#pragma execution_character_set("utf-8")
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    b1.setParent(this);
    b1.setText("close");
    b1.move(100,100);

    //指针需要分配空间
    b2 = new QPushButton(this);
    b2->setText("button2");


    connect(&b1,&QPushButton::pressed,this,&MainWidget::close);
    /*&b1:信号发出者，指针类型
     * &QPushButton::pressed:处理的信号，&发送者的类名::信号名字
     * this:信号接收者
     * &MainWidget::close:槽函数，信号处理函数 &接收的类名::槽函数名字

    */

    /*自定义槽
     * QT5:任意的成员函数，普通全局函数，静态函数
     * 槽函数需要和信号一致（参数，返回值）
     * 由于信号没有返回值，所以槽函数一定没有返回值

    */
    connect(b2,&QPushButton::released,this,&MainWidget::mySlot);
    connect(b2,&QPushButton::released,&b1,&QPushButton::hide);

    setWindowTitle("老大");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    resize(400,400);
    //显示子窗口
    son.show();

    connect(&b3,&QPushButton::released,this,&MainWidget::changeWin);

//    //处理子窗口的信号
//    void(SubWidget::*funSignal)()=&SubWidget::mySignals;
//    void(SubWidget::*testSignal)(int,QString)=&SubWidget::mySignals;
//    connect(&son,funSignal,this,&MainWidget::dealSub);

//    connect(&son,testSignal,this,&MainWidget::dealSlot);

    //QT4信号连接
    //QT4槽函数必须有slots关键字来修饰
    connect(&son,SIGNAL(mySignals()),this,SLOT(dealSub()));
    connect(&son,SIGNAL(mySignals(int,QString)),this,SLOT(dealSlot(int,QString)));
    //SIGNAL SLOT 讲函数名字转化为字符串，不进行错误检查

    //Lambda表达式,匿名函数对象
    //是c++11增加的新特性，项目文件:CONFIG += C++11
    //QT配合信号一起使用，非常方便
    QPushButton *b4 = new QPushButton(this);
    b4->setText("lambda表达式");
    b4->move(150,150);
    int a=10,b=100;
    connect(b4,&QPushButton::released,
            // =:把外部所有局部变量、类中所有成员以值传递
            // this:类中所有成员以值传递

        /*    [=]() mutable
            {
              b4->setText("123");
              qDebug()<<"1111";
              qDebug()<<a<<b;
              a = 11;//这样是错误的，要加mutable
            }
            );*/




}
void MainWidget::mySlot(){
    b2->setText("123");
}

void MainWidget::changeWin(){
    son.show();
    this->hide();
}
void MainWidget::dealSub(){
    son.hide();
    this->show();
}

void MainWidget::dealSlot(int a, QString str){
    //str.toUtf8():字节数组QByteArray
    //data():QByteArray->char*
    qDebug()<<a<<str.toUtf8().data();
}
MainWidget::~MainWidget()
{

}
