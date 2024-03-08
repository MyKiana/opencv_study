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
    openCamera();
}

void VideoPlay::getPicture() {

    if(!cap.isOpened()){
        qDebug() << "no open";
        return;
    }
    Mat frame;
    cap >> frame; // 从摄像头捕获一帧

    if (!frame.empty()) {
        cv::cvtColor(frame, frame, cv::COLOR_BGR2RGB); // 转换为RGB格式
        QImage img((const unsigned char*)(frame.data), frame.cols, frame.rows, frame.cols*frame.channels(), QImage::Format_RGB888);
        //ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(), Qt::KeepAspectRatio));
        ui->label->setPixmap(QPixmap::fromImage(img));
        ui->label->setScaledContents(true); // 启用内容缩放
    }
}

void VideoPlay::initTimer(int time) {
    m_time = time;
    // 初始化定时器
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &VideoPlay::getPicture);
    timer->start(m_time); // 每30毫秒捕获一帧
}

void VideoPlay::openCamera() {
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M','J','P','G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280); //图像的宽，需要相机支持此宽
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 720); //图像的高，需要相机支持此高

    int deviceID = 0; //相机设备号
    cap.open(deviceID); //打开相机

}

void VideoPlay::initUI() {
    ui->label->setFixedWidth(this->width());
    ui->label->setFixedHeight(this->height());
}

void VideoPlay::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    ui->label->setFixedWidth(this->width());
    ui->label->setFixedHeight(this->height());

    qDebug() << this->width() << "------------" << ui->label->width();
}
