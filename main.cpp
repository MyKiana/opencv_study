#include <QApplication>
#include <QPushButton>
#include "tool/tinyxml2.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget *widget = new QWidget();
    widget->resize(200, 100);
    widget->show();
    return QApplication::exec();
}
