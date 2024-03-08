//
// Created by Kiana on 2024/3/8.
//

#ifndef OPENCV_STUDY_VIDEOPLAY_H
#define OPENCV_STUDY_VIDEOPLAY_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <QTimer>

using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class VideoPlay; }
QT_END_NAMESPACE

class VideoPlay : public QWidget {
Q_OBJECT

public:
    explicit VideoPlay(QWidget *parent = nullptr);

    ~VideoPlay() override;

    void init();

    void initTimer(int time = 30);

public slots:
    void getPicture();

private:
    Ui::VideoPlay *ui;

    //定时多少毫秒
    int m_time;

    VideoCapture cap;   //声明相机捕获对象
};


#endif //OPENCV_STUDY_VIDEOPLAY_H
