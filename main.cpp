#include <QApplication>
#include <QPushButton>
#include "tool/tinyxml2.h"
#include "src/ui/VideoPlay.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    VideoPlay *v = new VideoPlay();
    v->show();
    return QApplication::exec();
}
