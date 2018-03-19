#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QWidget>
#include <QEvent>
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
    //不要用
    void mouseDoubleClickEvent(QMouseEvent *);
    void keyPressEvent(QKeyEvent *);
    void keyReleaseEvent(QKeyEvent *event);

signals:

public slots:
};

#endif // MYWIDGET_H
