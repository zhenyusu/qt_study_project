#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include <QEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPushButton>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    /*wigets的消息处理函数(所有的消息)*/
    bool event(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *event);

    QPushButton * button;

signals:

public slots:
};

#endif // MYWIDGET_H
