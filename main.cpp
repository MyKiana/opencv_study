#include <QApplication>
#include <QPushButton>
#include "tool/tinyxml2.h"
#include "src/ui/VideoPlay.h"
#include "USB/UsbTest.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    UsbTest *usb = new UsbTest();
    usb->openUSB();
    VideoPlay *v = new VideoPlay();
    v->setFixedHeight(700);
    v->setFixedWidth(1000);
    v->show();
    return QApplication::exec();
}
