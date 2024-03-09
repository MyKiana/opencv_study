//
// Created by Kiana on 2024/3/8.
//

#ifndef OPENCV_STUDY_TOOLAPPLY_H
#define OPENCV_STUDY_TOOLAPPLY_H
#include <QMutex>
#include <QObject>
#include <QCoreApplication>

class toolApply :public QObject{
    Q_OBJECT
public:
    toolApply();
    bool createConfigFile();
    static  toolApply* getInstance();

private:
    QString m_configPath;
    QString m_appPath;
    static toolApply* m_instance;
    static QMutex m_mutex;
};

#endif //OPENCV_STUDY_TOOLAPPLY_H
