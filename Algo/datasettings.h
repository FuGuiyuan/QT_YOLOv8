#ifndef DATASETTINGS_H
#define DATASETTINGS_H

#include <iostream>
#include "opencv2/opencv.hpp"

enum DETECT_ALGO_TYPE
{
    YOLOv5_DNN,
    YOLOv8_DNN,
    //FACE_DETECT
};

class dataSettings
{
public:
    dataSettings();

    std::string getData_path() const;
    void setData_path(const std::string &newData_path);
    std::string getWeight_file() const;
    void setWeight_file(const std::string &newWeight_file);
    std::string getConfig_file() const;
    void setConfig_file(const std::string &newConfig_file);
    bool getShow_fps() const;
    void setShow_fps(bool newShow_fps);
    bool getShow_score() const;
    void setShow_score(bool newShow_score);
    float getT_score() const;
    void setT_score(float newT_score);
    float getConf() const;
    void setConf(float newConf);
    int getInput_w() const;
    void setInput_w(int newInput_w);
    int getInput_h() const;
    void setInput_h(int newInput_h);
    DETECT_ALGO_TYPE getName() const;
    void setName(DETECT_ALGO_TYPE newName);

    //从参数文件里读
    void loadSettings();
    //写入到参数文件里
    void dumpSettings();

private:
    std::string data_path;
    std::string weight_file;
    std::string config_file;
    bool show_fps = true;
    bool show_score = true;
    float t_score = 0.25;
    float conf = 0.25;
    int input_w = 640;
    int input_h = 640;
    DETECT_ALGO_TYPE name = DETECT_ALGO_TYPE::YOLOv5_DNN;

};

#endif // DATASETTINGS_H
