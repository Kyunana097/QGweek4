# 基于I2C通信协议的OLED驱动程序

## 程序介绍

`本项目是基于I2C通信协议，AT89C52单片机驱动的OLED程序，可驱动0.96寸OLED屏幕显示最大128*64像素的BMP图片，显示汉字，循环播放常用ASCII表`

## 目录结构

```
OLED_I2C
│  README.md
│  
├─bin		//可执行文件
│      project.hex
│      
├─inc		//头文件
│      bmp.h
│      oled.h
│      oledfont.h
│      
└─src		//源代码
        main.c
        oled.c
```

