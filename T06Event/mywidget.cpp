#include "mywidget.h"
#include <QApplication>
#include <QEvent>
#include <QDebug>
#include <QPoint>
#include <QMouseEvent>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
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

    QPoint pt = ev->pos();
    qDebug() << pt;
    //判断是左键是否被按下
    if(ev->button() == Qt::LeftButton){

    }
    if(ev->modifiers() == Qt::ShiftModifier){
        qDebug() << "shift press";
    }
}


void MyWidget::mouseMoveEvent(QMouseEvent *){}
void MyWidget::keyPressEvent(QKeyEvent *){}
void MyWidget::keyReleaseEvent(QKeyEvent *){}

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    MyWidget w;
    w.show();
    return app.exec();
}

