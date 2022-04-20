/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-17 14:38:06
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-18 18:21:57
 */

#ifndef RECORD_EVENT_DATA_STEREO
#define RECORD_EVENT_DATA_STEREO

#include <opencv2/opencv.hpp>
#include "../include/celex5/celex5.h"
#include "../include/celex5/celex5datamanager.h"

#include "comment.hpp"
#include <string>
#include <vector>

using std::cout;
using std::cerr;
using std::clog;
using std::endl;
using std::string;
using std::vector;

class RecordEventDataStereo
{
public:
    RecordEventDataStereo(const string fpnFile1 = "../config/FPN_M_2.txt", const string fpnFile2 = "../config/FPN_S_2.txt");

    int StartRecord(const string binFile, int device_index);
    int StopRecord(int device_index);

    int setLoopMode();
    int setFixedMode();
    int setMixedMode();

    int process();

public:
    CeleX5* pCeleX5;

private:
    int beginProcess();
    int takeAVideo(string basePath1,string basePath2, int actionNo, int personNo);

private:
    vector<string> vecCeleX5Mode;

    cv::Mat mR;
    cv::Mat mG;
};

#endif