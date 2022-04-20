/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-03-28 20:50:08
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-18 16:22:25
 */
#ifndef RECORD_EVENT_DATA
#define RECORD_EVENT_DATA

#include "../include/CeleX/celex5/celex5.h"
#include "comment.hpp"
#include <string>
#include <vector>

using std::cout;
using std::cerr;
using std::clog;
using std::endl;
using std::string;
using std::vector;

class RecordEventData
{
public:
    RecordEventData(const string fpnFile = "./FPN_2.txt");

    int StartRecord(const string binFile);
    int StopRecord();

    int setLoopMode();
    int setFixedMode();

    int process();

public:
    CeleX5* pCeleX5;

private:
    int beginProcess();
    int takeAVideo(int actionNo, int personNo);

private:
    vector<string> vecCeleX5Mode;

    cv::Mat mR;
    cv::Mat mG;
};

#endif