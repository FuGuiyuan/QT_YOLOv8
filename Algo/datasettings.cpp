#include "datasettings.h"

dataSettings::dataSettings(DETECT_ALGO_TYPE Name)
{
    this->name = Name;
}

std::string dataSettings::getData_path() const
{
    return data_path;
}

void dataSettings::setData_path(const std::string &newData_path)
{
    data_path = newData_path;
}

std::string dataSettings::getWeight_file() const
{
    return weight_file;
}

void dataSettings::setWeight_file(const std::string &newWeight_file)
{
    weight_file = newWeight_file;
}

std::string dataSettings::getConfig_file() const
{
    return config_file;
}

void dataSettings::setConfig_file(const std::string &newConfig_file)
{
    config_file = newConfig_file;
}

bool dataSettings::getShow_fps() const
{
    return show_fps;
}

void dataSettings::setShow_fps(bool newShow_fps)
{
    show_fps = newShow_fps;
}

bool dataSettings::getShow_score() const
{
    return show_score;
}

void dataSettings::setShow_score(bool newShow_score)
{
    show_score = newShow_score;
}

float dataSettings::getT_score() const
{
    return t_score;
}

void dataSettings::setT_score(float newT_score)
{
    t_score = newT_score;
}

float dataSettings::getConf() const
{
    return conf;
}

void dataSettings::setConf(float newConf)
{
    conf = newConf;
}

int dataSettings::getInput_w() const
{
    return input_w;
}

void dataSettings::setInput_w(int newInput_w)
{
    input_w = newInput_w;
}

int dataSettings::getInput_h() const
{
    return input_h;
}

void dataSettings::setInput_h(int newInput_h)
{
    input_h = newInput_h;
}

DETECT_ALGO_TYPE dataSettings::getName() const
{
    return name;
}

void dataSettings::setName(DETECT_ALGO_TYPE newName)
{
    name = newName;
}

void dataSettings::loadSettings()
{
    if(name == DETECT_ALGO_TYPE::YOLOv5_DNN)
    {
        //FileStorage::READ 打开文件进行读操作
        //FileStorage::WRITE 打开文件进行写操作
        //FileStorage::APPEND打开文件进行附加操作，在已有内容的文件里添加
        cv::FileStorage fs("YOLOv5_detector_settings.yml",cv::FileStorage::READ);
        //如果文件没有打开
        if(!fs.isOpened())
        {
            std::cout<<"could not open the file"<<std::endl;
            return;
        }
        fs["weight_file"] >> weight_file;
        fs["config_file"] >> config_file;
        fs["t_score"] >> t_score;
        fs["show_fps"] >> show_fps;
        fs["show_score"] >> show_score;
        //读完 关闭文件
        fs.release();
    }

    //YOLOv8。。。。


}

void dataSettings::dumpSettings()
{
    if(name ==DETECT_ALGO_TYPE::YOLOv5_DNN)
    {
        //写数据
        cv::FileStorage fs("YOLOv5_detector_settings.yml",cv::FileStorage::WRITE);
        fs<<"weight_file"<<weight_file;
        fs<<"config_file"<< this->config_file;
        fs<<"t_score"<< this->t_score;
        fs<<"conf"<< this->conf;
        fs<<"show_fps"<< this->show_fps;
        fs<<"show_score"<< this->show_score;
        fs.release();
    }

    //YOLOv8。。。。

}
