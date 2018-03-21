#include "subwidget.h"
#pragma execution_character_set("utf-8")
SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("小弟");
    resize(400,400);
    b3.setParent(this);
    b3.setText("切换到主窗口");
    connect(&b3,&QPushButton::clicked,this,&SubWidget::sendSlot);

}

void SubWidget::sendSlot(){
    emit mySignals();
    emit mySignals(250,"我是子窗口");
}
