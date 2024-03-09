//
// Created by Kiana on 2024/3/8.
//

#ifndef OPENCV_STUDY_USBTEST_H
#define OPENCV_STUDY_USBTEST_H
#include <QObject>

class UsbTest : public QObject{
Q_OBJECT

public:
    UsbTest();
    void openUSB();

    void usbTest();

};
#endif //OPENCV_STUDY_USBTEST_H
