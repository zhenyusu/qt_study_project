#include "mywidget.h"
#include <QApplication>
#include <QEvent>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
#include <QKeyEvent>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    button = new QPushButton("OK",this);
    button->setDefault(true);
    //鼠标不需要按下，MouseMove就能得到调用
    this->setMouseTracking(true);
}

// QApplication 先得到->具体应该处理的窗口::event()->event()根据消息的类型来调用具体的虚函数
/*1.可以重载具体的虚函数，来实现对消息的响应
 *2.可以重载event函数，用来处理或者截取消息*/


//截断消息
bool MyWidget::event(QEvent *ev){
    //鼠标消息被截断了
    if(ev->type()== QEvent::MouseButtonPress){
        return true;
    }
    return QWidget::event(ev);
}

//打印鼠标位置
void MyWidget::mousePressEvent(QMouseEvent *ev){
#if 0
    QPoint pt = ev->pos();
    qDebug() << pt;
    //判断是左键是否被按下
    if(ev->button() == Qt::LeftButton){

    }
    //判断shift+鼠标
    if(ev->modifiers() == Qt::ShiftModifier){
        qDebug() << "shift press";
    }
#endif
    //判断ctrl+鼠标
    if(ev->modifiers()==Qt::ControlModifier){
        //handle with control;
        return;

    }
    // handle2 without control;
}

//鼠标移动事件(需要点击左键移动)
void MyWidget::mouseMoveEvent(QMouseEvent *){
    static int i = 0;
    qDebug()<<i++;
}

//响应键盘按下事件
void MyWidget::keyPressEvent(QKeyEvent *ev){
    int key = ev->key();
    qDebug() << (char)key;
}
void MyWidget::keyReleaseEvent(QKeyEvent *){}
void MyWidget::mouseReleaseEvent(QMouseEvent *){}

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MyWidget w;
    w.show();
    return app.exec();
}

