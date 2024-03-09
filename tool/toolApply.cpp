//
// Created by Kiana on 2024/3/8.
//

#include <QFile>
#include <QDebug>
#include "toolApply.h"
#include "tinyxml2.h"

toolApply *toolApply::m_instance = nullptr;
QMutex toolApply::m_mutex;

bool toolApply::createConfigFile() {
    const char* declaration =R"(<?xml version="1.0" encoding="UTF-8" standalone="no"?>)";
    tinyxml2::XMLDocument doc;
    doc.Parse(declaration);//会覆盖xml所有内容

    ///创建一个新的XML元素 Sys //
    tinyxml2::XMLElement* root=doc.NewElement("Sys");

    ///添加到XML文档的末尾 ///
    doc.InsertEndChild(root);
    return true;
}

toolApply::toolApply() {
    //获取程序路径
    m_appPath = QCoreApplication::applicationDirPath();

    m_configPath = m_appPath + "/config.xml";
    qDebug() << m_configPath;

    //如果文件不存在就创建
    QFile file(m_configPath);
    if (!file.exists()) {
        createConfigFile();
    }
    file.close();
}

toolApply *toolApply::getInstance() {
    if (m_instance == nullptr) {
        ///上锁
        m_mutex.lock();
        if (m_instance == nullptr) {
            m_instance = new toolApply();
        }
        ///解锁
        m_mutex.unlock();
    }
    return m_instance;
}
