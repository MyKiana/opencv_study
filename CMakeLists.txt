cmake_minimum_required(VERSION 3.27)
project(opencv_study)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "D:/SoftWare/Qt/5.14.2/msvc2017_64")
set(OpenCV_DIR "D:/SoftWare/opencv/opencv4.7.0_notcuda/x64/vc15/lib")

set(LIBUSB_DIR "E:/Lib_home/LibUSB/libusb-1.0.27/libusb")
set(LIBUSB_LIB "E:/Lib_home/LibUSB/libusb-1.0.27/build/v143/x64/Debug/lib/libusb-1.0.lib" )

find_package(OpenCV REQUIRED)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${LIBUSB_DIR}
)
link_directories(
        ${OpenCV_LIBS}
        ${LIBUSB_LIB}
)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(opencv_study main.cpp
        src/ui/VideoPlay.cpp
        tool/tinyxml2.cpp
        tool/toolApply.cpp
        tool/toolApply.h
        USB/UsbTest.cpp
        USB/UsbTest.h)


target_link_libraries(opencv_study
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        ${OpenCV_LIBS}
        ${LIBUSB_LIB}
)

if (WIN32 AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt5${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
