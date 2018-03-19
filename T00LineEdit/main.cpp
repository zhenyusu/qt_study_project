#include <QApplication>
#include <QWidget>
#include <QLineEdit>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    //构建一个主窗口
    QWidget w;

    //构建一个文本行
    QLineEdit edit;
    edit.setParent(&w);
    edit.show();

    return app.exec();
}
