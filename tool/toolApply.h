//
// Created by Kiana on 2024/3/8.
//

#ifndef OPENCV_STUDY_TOOLAPPLY_H
#define OPENCV_STUDY_TOOLAPPLY_H

#include <QObject>

class toolApply :public QObject{
    Q_OBJECT
public:
    bool createConfigFile();

private:
};

#endif //OPENCV_STUDY_TOOLAPPLY_H
