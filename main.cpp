#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget *widget = new QWidget();
    widget->resize(200, 100);
    widget->show();
    return QApplication::exec();
}
