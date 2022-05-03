/*
 * @Descripttion: 用于启动CeleX5 Event相机并记录事件及灰度图像
 * @version: 
 * @Author: guanzhou
 * @Date: 2021-01-09 02:59:46
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-03 19:14:29
 */
#include "RecordEventData.hpp"

RecordEventData::RecordEventData(const string fpnFile)
{
    pCeleX5 = new CeleX5();
    if(NULL == pCeleX5)
    {
        cerr << __FILE__ << "\t" << __func__ << endl;
        return;
    }
    pCeleX5->openSensor(CeleX5::CeleX5_MIPI);
    pCeleX5->setFpnFile(fpnFile);

    vecCeleX5Mode.emplace_back("Event_Off_Pixel_Timestamp_Mode");
    vecCeleX5Mode.emplace_back("Event_In_Pixel_Timestamp_Mode");
    vecCeleX5Mode.emplace_back("Event_Intensity_Mode");
    vecCeleX5Mode.emplace_back("Full_Picture_Mode");
    vecCeleX5Mode.emplace_back("Optical_Flow_Mode");
    vecCeleX5Mode.emplace_back("Optical_Flow_FPN_Mode");
    vecCeleX5Mode.emplace_back("Multi_Read_Optical_Flow_Mode");


    // mR = cv::imread("../rosgraph.png");
    // mG = cv::imread("../rosgraph.png");
    mR = cv::Mat(cv::Size(500,500),CV_8UC3,cv::Scalar(0,0,255));
    mG = cv::Mat(cv::Size(500,500),CV_8UC3,cv::Scalar(0,255,0));
    imgHelper.addImage("prompt", mR);
}

RecordEventData::~RecordEventData()
{
    close();
    if(pCeleX5)
    {
        delete pCeleX5;
    }
}

int RecordEventData::StartRecord(const string binFile)
{
    if(!pCeleX5)
    {
        return -1;
    }
    if(pCeleX5->isLoopModeEnabled())
    {
        clog << __func__ << ":\nstart record in loop mode\n";
        for(int i = 1; i <= 3;++i)
        {
            clog << std::to_string(i) << ":\t" << vecCeleX5Mode[pCeleX5->getSensorLoopMode(i)] << endl;;
        }
    }else
    {
        clog << __func__ << ":\tstart record in fixed mode (" 
        + vecCeleX5Mode[pCeleX5->getSensorFixedMode()] + ")\n";
    }
    pCeleX5->startRecording(binFile); 
    return State_OK;
}

int RecordEventData::StopRecord()
{
    if(!pCeleX5)
    {
        return -1;
    }
    pCeleX5->stopRecording();
    clog << __func__ << "\n";

    imgHelper.addImage("prompt", mR);

    return State_OK;
}

int RecordEventData::setLoopMode()
{
    if(!pCeleX5)
    {
        return -1;
    }
    pCeleX5->setLoopModeEnabled(true);

	pCeleX5->setSensorLoopMode(CeleX5::Full_Picture_Mode, 1);
	pCeleX5->setSensorLoopMode(CeleX5::Event_Intensity_Mode, 2);
	pCeleX5->setSensorLoopMode(CeleX5::Optical_Flow_Mode, 3);

    return State_OK;
}

int RecordEventData::setFixedMode()
{
    if(!pCeleX5)
    {
        return -1;
    }
    pCeleX5->setLoopModeEnabled(false);
    pCeleX5->setSensorFixedMode(CeleX5::CeleX5Mode::Event_Intensity_Mode);

    return State_OK;
}

int RecordEventData::beginProcess()
{
    imgHelper.addImage("prompt", mR);
    return State_OK;
}

int RecordEventData::takeAVideo(int actionNo, int personNo)
{
    beginProcess();
    string path = "../bin/dataset/";
    if(actionNo < 10)
    {
        path += "0";
    }
    
    path += std::to_string(actionNo);
    path += "/";

    if(personNo < 10)
    {
        path += "0";
    }
    path += std::to_string(personNo);
    path += "/";

    makeFolder(path);

    vector<string> files;
    int size = getFiles(path, files);
    path += std::to_string(size) + ".bin";
    
    imgHelper.addImage("prompt", mG);
    StartRecord(path);

    
    return State_OK;
}

int RecordEventData::process()
{
    int person, action;
    beginProcess();
    while(cin>>person>>action)
    {
        takeAVideo(action, person);
        beginProcess();
    }
    return State_OK;
}

void RecordEventData::showImages()
{
    if(!pCeleX5)
    {
        return;
    }
    // fpConnectionRunning();
    imgHelper.start();
    start();
}

void RecordEventData::fpConnectionRunning()
{
    cout << __func__ << "=============================start showImages\n";
    while(m_isRunning)
    {
        auto img = pCeleX5->getEventPicMat(CeleX5::EventGrayPic);
        if(!img.empty())
        {
            imgHelper.addImage("img", img);
        }
        usleep(30 * 1000);
    }
    cout << __func__ << "=============================end showImages\n";
}

int RecordEventData::close()
{
    m_isRunning = false;
}