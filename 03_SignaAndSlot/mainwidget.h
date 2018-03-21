#ifndef MAINWIDGET_H
#define MAINWIDGET_H
#include "subwidget.h"//子窗口头文件
#include <QWidget>
#include <QPushButton>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();
public slots:
    void mySlot();
    void changeWin();
    void dealSub();
    void dealSlot(int,QString);

private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;
    SubWidget son;
};

#endif // MAINWIDGET_H
