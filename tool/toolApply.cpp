//
// Created by Kiana on 2024/3/8.
//

#include "toolApply.h"
#include "tinyxml2.h"

bool toolApply::createConfigFile() {
    const char* declaration =R"(<?xml version="1.0" encoding="UTF-8" standalone="no"?>)";
    tinyxml2::XMLDocument doc;
    doc.Parse(declaration);//会覆盖xml所有内容

    return true;
}
