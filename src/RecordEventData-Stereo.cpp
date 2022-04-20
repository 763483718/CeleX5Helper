/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-17 14:37:56
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-20 20:49:09
 */

#include "RecordEventData-Stereo.hpp"


RecordEventDataStereo::RecordEventDataStereo(const string fpnFile1, const string fpnFile2)
{
    pCeleX5 = new CeleX5();
    if(NULL == pCeleX5)
    {
        cerr << __FILE__ << "\t" << __func__ << endl;
        return;
    }
    pCeleX5->openSensor(CeleX5::CeleX5_MIPI);
    pCeleX5->setFpnFile(fpnFile1, 0);
    pCeleX5->setFpnFile(fpnFile2, 1);

    vecCeleX5Mode.emplace_back("Event_Off_Pixel_Timestamp_Mode");
    vecCeleX5Mode.emplace_back("Event_In_Pixel_Timestamp_Mode");
    vecCeleX5Mode.emplace_back("Event_Intensity_Mode");
    vecCeleX5Mode.emplace_back("Full_Picture_Mode");
    vecCeleX5Mode.emplace_back("Optical_Flow_Mode");
    vecCeleX5Mode.emplace_back("Optical_Flow_FPN_Mode");
    vecCeleX5Mode.emplace_back("Multi_Read_Optical_Flow_Mode");

    mR = cv::Mat(cv::Size(500,500),CV_8UC3,cv::Scalar(0,0,255));
    mG = cv::Mat(cv::Size(500,500),CV_8UC3,cv::Scalar(0,255,0));
}


int RecordEventDataStereo::StartRecord(const string binFile, int device_index)
{
    if(pCeleX5->isLoopModeEnabled(device_index))
    {
        clog << __func__ << ":\nstart record in loop mode\n";
        for(int i = 1; i <= 3;++i)
        {
            clog << std::to_string(i) << ":\t" << vecCeleX5Mode[pCeleX5->getSensorLoopMode(i, device_index)] << endl;;
        }
    }else
    {
        clog << __func__ << ":\tstart record in fixed mode (" 
        + vecCeleX5Mode[pCeleX5->getSensorFixedMode(device_index)] + ")\n";
    }
    pCeleX5->startRecording(binFile, device_index); 
    return State_OK;
}

int RecordEventDataStereo::StopRecord(int device_index)
{
    pCeleX5->stopRecording(device_index);
    clog << __func__ << "\n";

    cv::imshow("prompt", mR);

    return State_OK;
}

int RecordEventDataStereo::setLoopMode()
{
    for(int device_index = 0; device_index < 2;++device_index)
    {
        pCeleX5->setLoopModeEnabled(true, device_index);

        pCeleX5->setSensorLoopMode(CeleX5::Full_Picture_Mode, 1, device_index);
        pCeleX5->setSensorLoopMode(CeleX5::Event_Intensity_Mode, 2, device_index);
        pCeleX5->setSensorLoopMode(CeleX5::Full_Optical_Flow_S_Mode, 3, device_index);
    }
    return State_OK;
}

int RecordEventDataStereo::setFixedMode()
{
    for(int device_index = 0; device_index < 2; device_index++)
    {
        pCeleX5->setLoopModeEnabled(false, device_index);
        pCeleX5->setSensorFixedMode(CeleX5::CeleX5Mode::Event_Intensity_Mode, device_index);
    }
    return State_OK;
}

int RecordEventDataStereo::setMixedMode()
{
    pCeleX5->setLoopModeEnabled(true, 0);
    pCeleX5->setSensorLoopMode(CeleX5::Full_Picture_Mode, 1, 0);
    pCeleX5->setSensorLoopMode(CeleX5::Event_Intensity_Mode, 2, 0);
    pCeleX5->setSensorLoopMode(CeleX5::Event_Address_Only_Mode, 3, 0);

    pCeleX5->setLoopModeEnabled(false, 1);
    pCeleX5->setSensorFixedMode(CeleX5::CeleX5Mode::Event_Intensity_Mode, 1);
    return State_OK;
}

int RecordEventDataStereo::process()
{
    int person, action;
    beginProcess();
    string basePath1 = "../bin/dataset/camera1/";
    string basePath2 = "../bin/dataset/camera2/";
    while(cin >> person >> action)
    {
        takeAVideo(basePath1, basePath2, action, person);
        beginProcess();
    }
    return State_OK;
}

int RecordEventDataStereo::beginProcess()
{
    cv::imshow("prompt",mR);
    cv::waitKey(0);
    return State_OK;
}

int RecordEventDataStereo::takeAVideo(string basePath1, string basePath2, int actionNo, int personNo)
{
    string path;
    if(basePath1.back() != '/')
    {
        path += '/';
    }
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

    makeFolder(basePath1 + path);
    makeFolder(basePath2 + path);

    vector<string> files;
    int size = getFiles(basePath1 + path, files);
    path += std::to_string(size) + ".bin";

    cv::imshow("prompt",mG);
    StartRecord(basePath1 + path, 0);
    // StartRecord(basePath2 + path, 1);
    cv::waitKey(0);
    StopRecord(0);
    // StopRecord(1);

    return State_OK; 
}