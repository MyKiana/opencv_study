//
// Created by Kiana on 2024/3/8.
//

#include "UsbTest.h"
#include <libusb.h>
#include <QDebug>

UsbTest::UsbTest() {
    //openUSB();
}

///打开USB设备///
void UsbTest::openUSB() {
    libusb_context *ctx = nullptr;
    libusb_device **devs; // 指向设备指针的指针
    ssize_t cnt; // 设备数量
    int r; // 用于存储返回值
    unsigned char strdesc[256]; // 存放字符串描述符的缓冲区
    int index; // 字符串描述符的索引
    libusb_device_handle *dev_handle; // 设备句柄

    r = libusb_init(&ctx);
    if(r < 0) {
        qDebug() << "init libusb error";
        return;
    }

    libusb_set_debug(ctx, 3); // 设置日志级别（可选）
    cnt = libusb_get_device_list(ctx, &devs); // 获取设备列表
    if(cnt < 0) {
        qDebug() << "get device fail";
        libusb_exit(ctx); // 清理并退出
        return;
    }

    qDebug() << "USB count：" << cnt;
    for(ssize_t i = 0; i < cnt; i++) {
        libusb_device *dev = devs[i];
        libusb_device_descriptor desc;
        r = libusb_get_device_descriptor(dev, &desc);
        if(r < 0) {
            qDebug() << "get fu error";
            continue;
        }

        // 尝试打开设备
//        r = libusb_open(dev, &dev_handle);
//        if(r < 0) {
//            qDebug() << "open false";
//            continue;
//        }

        qDebug() << "Vendor ID: " << desc.idVendor
                 << "Product ID: " << desc.idProduct;

        // 获取设备制造商和产品名称
        index = desc.iManufacturer;
        if(index > 0) {
            r = libusb_get_string_descriptor_ascii(dev_handle, index, strdesc, sizeof(strdesc));
            if(r > 0) {
                qDebug() << "shang: " << strdesc;
            } else {
                qDebug() << "shang s";
            }
        }

        index = desc.iProduct;
        if(index > 0) {
            r = libusb_get_string_descriptor_ascii(dev_handle, index, strdesc, sizeof(strdesc));
            if(r > 0) {
                qDebug() << "chanp: " << strdesc;
            } else {
                qDebug() << "chanps ";
            }
        }

        // 关闭设备句柄
        libusb_close(dev_handle);

        // 可以在这里添加更多设备信息的输出
    }

    // 释放设备列表
    libusb_free_device_list(devs, 1);

    // 清理并退出libusb上下文
    libusb_exit(ctx);
}

void UsbTest::usbTest() {
    // reference: examples/listdevs.c
    int ret = libusb_init(nullptr);
    if (ret != 0) {
        fprintf(stderr, "fail to init: %d\n", ret);
        return ;
    }

    libusb_device** devs = nullptr;
    ssize_t count = libusb_get_device_list(nullptr, &devs);
    if (count < 0) {
        fprintf(stderr, "fail to get device list: %d\n", count);
        libusb_exit(nullptr);
        return ;
    }

    libusb_device* dev = nullptr;
    int i = 0;

    while ((dev = devs[i++]) != nullptr) {
        struct libusb_device_descriptor desc;
        ret = libusb_get_device_descriptor(dev, &desc);
        if (ret < 0) {
            fprintf(stderr, "fail to get device descriptor: %d\n", ret);
            return;
        }

        fprintf(stdout, "%04x:%04x (bus: %d, device: %d) ",
                desc.idVendor, desc.idProduct, libusb_get_bus_number(dev), libusb_get_device_address(dev));

        uint8_t path[8];
        ret = libusb_get_port_numbers(dev, path, sizeof(path));
        if (ret > 0) {
            fprintf(stdout, "path: %d", path[0]);
            for (int j = 1; j < ret; ++j)
                fprintf(stdout, ".%d", path[j]);
        }
        fprintf(stdout, "\n");
    }

    libusb_free_device_list(devs, 1);
    libusb_exit(nullptr);

}
