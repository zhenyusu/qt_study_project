#include <QApplication>
#include <Qwidget>
#include<QPushButton>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLabel>
int main(int argc, char * argv[]){
    QApplication app(argc,argv);
    QWidget w;
#if 0
    QPushButton button;
    button.setText("Button");
    button.setParent(&w);
    //(x,y,length,width)基于父对象的坐标

    button.show();

    QLineEdit edit;
    edit.setParent(&w);
#endif
#if 0
    //垂直布局
    QVBoxLayout layout;
    layout.addWidget(&button);
    layout.addWidget(&edit)
 #endif

#if 0
    //水平布局
    QHBoxLayout layout;
    layout.addWidget(&button);
    layout.addWidget(&edit);
    layout.addStretch(1);//设置弹簧

#endif

#if 0
    //格子布局
    QGridLayout layout;
    layout.addWidget(&button,1,1);
    layout.addWidget(&edit,1,2);
    layout.addWidget(new QPushButton("button1"),2,1);
    layout.addWidget(new QPushButton("button2"),2,2);
    //按钮占一行两列
    layout.addWidget(new QPushButton("button3"),3,1,1,2);
    layout.setColumnStretch(0,1);//第1列加弹簧
    layout.setRowStretch(0,1);//第1行加弹簧
    layout.setColumnStretch(3,1);//第三行加弹簧
    layout.setRowStretch(4,1);//第三列加弹簧
#endif

    QGridLayout layout;
    QLineEdit *password;
    layout.setColumnStretch(0,1);//第1列加弹簧
    layout.setRowStretch(0,1);//第1行加弹簧
    layout.setColumnStretch(3,1);//第三行加弹簧
    layout.setRowStretch(4,1);//第三列加弹簧

    layout.addWidget(new QLabel("UserName:"),1,1);
    layout.addWidget(new QLineEdit(),1,2);
    layout.addWidget(new QLabel("PassWord"),2,1);
    layout.addWidget(password = new QLineEdit(),2,2);

    QHBoxLayout *hBox;
    layout.addLayout(hBox = new QHBoxLayout,3,2);
    hBox->addStretch(1);
    hBox->addWidget(new QPushButton("Login"));
    password->setEchoMode(QLineEdit::Password);

   // layout.addWidget(new QPushButton("登录"),3,2);

    //edit.show();
    w.show();//显示窗口
    w.setLayout(&layout);
   // QObject::connect(&button,SIGNAL(clicked()),&w,SLOT(close()));

    return app.exec();
}
