#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include<QCompleter>
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    //构建一个主窗口
    QWidget w;

    //构建一个文本行
    QLineEdit edit;
    edit.show();
    edit.setParent(&w);

    /*输入密码*/
    edit.setEchoMode(QLineEdit::Password);
    //输入提示
    edit.setPlaceholderText("please input text");
    //自动补全功能
    QCompleter completer(QStringList()<<"aab"<<"123"<<"998");
    //设置自动补全模式
    completer.setFilterMode(Qt::MatchContains);
    edit.setCompleter(&completer);

    //显示窗口
    w.show();
    return app.exec();
}
