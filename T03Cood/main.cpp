#include <QApplication>
#include <Qwidget>
#include<QPushButton>
int main(int argc, char * argv[]){
    QApplication app(argc,argv);
    QWidget w;
    w.show();//显示窗口
    QPushButton button;
    button.setText("Button");
    button.setParent(&w);
    //(x,y,length,width)基于父对象的坐标
    button.setGeometry(30,30,100,30);
    button.show();
    QObject::connect(&button,SIGNAL(clicked()),&w,SLOT(close()));

    return app.exec();
}
