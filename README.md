# 结合QT和OpenCV实现YOLO目标检测
## 内容
· 基于QT基本控件实现可视化目标检测信息，通过QT信号槽和事件响应机制实现人为调整算法参数设置以及图片视频显示效果。
· 使用OpenCV中DNN模块来实现YOLOv5和YOLOv8目标检测模型的加载，图像预处理，模型推理以及后处理内容。
· 使用QT多线程执行神经网络模型计算推理的长耗时任务，并自定义信号实现数据交换。
· 基于工厂模式实现目标检测算法创建，方便后续对添加新模型算法的扩展。


## 界面功能展示
![image](https://github.com/user-attachments/assets/3f259b11-2fc5-46a5-a314-6eeb5c373c35)


![image](https://github.com/user-attachments/assets/fb7b03aa-2ff5-4dcb-986b-7ce403d11da4)



![image](https://github.com/user-attachments/assets/20c445e0-3b3b-4d47-94d8-21839c9aafd9)
