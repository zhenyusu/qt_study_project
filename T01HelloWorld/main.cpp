/*应用程序抽象类*/
#include <QApplication>

/*窗口抽象类*/
#include <Qwidget>

/*按钮*/
#include<QPushButton>
int main(int argc, char * argv[]){
    QApplication app(argc,argv);
    /*构造一个窗口*/
    QWidget w;

    /*按钮也是一个窗口*/
    QPushButton button;
    button.setText("Button");

    /*窗口对象的父子关系影响显示位置*/
    /*没有父亲窗口的窗口为主窗口*/
    button.setParent(&w);
//    button.show();

    w.show();
    /*QT对C++的拓展*/
    QObject::connect(&button,SIGNAL(clicked()),&w,SLOT(close()));

    /*消息循环*/
    return app.exec();
}
