//
// Created by Kiana on 2024/3/8.
//

// You may need to build the project (run Qt uic code generator) to get "ui_VideoPlay.h" resolved

#include "VideoPlay.h"
#include "ui_VideoPlay.h"
#include <QDebug>


VideoPlay::VideoPlay(QWidget *parent) :
        QWidget(parent), ui(new Ui::VideoPlay) {
    ui->setupUi(this);
    initTimer();
    init();
}

VideoPlay::~VideoPlay() {
    delete ui;
}

void VideoPlay::init() {


}

void VideoPlay::getPicture() {

    Mat frame;
    cap >> frame; // 从摄像头捕获一帧

    if (!frame.empty()) {
        qDebug() << "get";
        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB); // 转换为RGB格式
        QImage img((const unsigned char*)(frame.data), frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_RGB888);
        ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(), Qt::KeepAspectRatio));
    }
    qDebug() << "no_get";
}

void VideoPlay::initTimer(int time) {
    m_time = time;
    // 初始化定时器
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &VideoPlay::getPicture);
    timer->start(m_time); // 每30毫秒捕获一帧
}
