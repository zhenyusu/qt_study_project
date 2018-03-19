#include "mywidget.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit>
#include <QTextBrowser> //只读的文本框
#include <QGroupBox> //用来分类
#include <QSlider> //模拟显示数值
#include <QSpinBox> //数字
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QVBoxLayout>
MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *lay = new QVBoxLayout(this);
    lay->addWidget();

}

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    MyWidget w;
    return 0;
}

