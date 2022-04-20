/*
* Copyright (c) 2017-2020 CelePixel Technology Co. Ltd. All Rights Reserved
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIOPNS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>
#include <celex5/celex5.h>
#include <celex5/celex5datamanager.h>
#include <celex5/celex5processeddata.h>

#ifdef _WIN32
#include <windows.h>
#else
#include<unistd.h>
#endif

#define FPN_PATH    "../Samples/config/FPN_2.txt"
//#define BIN_FILE    "YOUR_BIN_FILE_PATH.bin"	//your bin file path
#define BIN_FILE    "/home/tuto/code/recordEventDataSet/bin/dataset/camera1/00/00/1.bin"	//your bin file path

CeleX5 *pCeleX5 = new CeleX5;

class SensorDataObserver : public CeleX5DataManager
{
public:
	SensorDataObserver(CX5SensorDataServer* pServer)
	{
        tick = 0;
        fOut.open("/home/tuto/code/recordEventDataSet/bin/test.txt", std::ios::trunc | std::ios::in);

		m_pServer = pServer;
		m_pServer->registerData(this, CeleX5DataManager::CeleX_Frame_Data);
	}
	~SensorDataObserver()
	{

        fOut.close();

		m_pServer->unregisterData(this, CeleX5DataManager::CeleX_Frame_Data);
	}
	virtual void onFrameDataUpdated(CeleX5ProcessedData* pSensorData);//overrides Observer operation

	CX5SensorDataServer* m_pServer;


private:
    std::ofstream fOut;
    unsigned int tick;
};

uint8_t * pImageBuffer = new uint8_t[CELEX5_PIXELS_NUMBER];
void SensorDataObserver::onFrameDataUpdated(CeleX5ProcessedData* pSensorData)
{
	if (NULL == pSensorData)
		return;
	CeleX5::CeleX5Mode sensorMode = pSensorData->getSensorMode();
	if (CeleX5::Full_Picture_Mode == sensorMode)
	{
		//full-frame picture
		pCeleX5->getFullPicBuffer(pImageBuffer);
		cv::Mat matFullPic(800, 1280, CV_8UC1, pImageBuffer);
		cv::imshow("FullPic", matFullPic);
		cv::waitKey(1);
	}
	else if (CeleX5::Event_Off_Pixel_Timestamp_Mode == sensorMode)
	{
		//get buffers when sensor works in EventMode
		pCeleX5->getEventPicBuffer(pImageBuffer, CeleX5::EventBinaryPic);
		cv::Mat matEventPic(800, 1280, CV_8UC1, pImageBuffer);
		cv::imshow("Event Binary Pic", matEventPic);
		cvWaitKey(1);
	}
	else if (CeleX5::Optical_Flow_Mode == sensorMode)
	{
		//full-frame optical-flow pic
		pCeleX5->getOpticalFlowPicBuffer(pImageBuffer, CeleX5::OpticalFlowPic);
		cv::Mat matOpticalFlow(800, 1280, CV_8UC1, pImageBuffer);
		cv::imshow("Optical-Flow Pic", matOpticalFlow);
		cvWaitKey(1);
	}
    else if (CeleX5::Event_Intensity_Mode == sensorMode)
	{

        std::vector<EventData> vecEvent;
        pCeleX5->getEventDataVector(vecEvent);
        for(auto event : vecEvent)
        {
            
            if(event.col + 1 <= 240 || event.col + 1 > 1040)
            {
                continue;
            }

            fOut << tick + event.tOffPixelIncreasing;//tOffPixelIncreasing;
            fOut << " ";
            fOut << (event.row) ;
            fOut << " ";
            fOut << (event.col - 240) ;
            fOut << " ";

            if(event.polarity == 1)
            {
                fOut << 1;
                fOut << std::endl;
            }else
            {
                fOut << 0;
                fOut << std::endl;
            }
        }
        tick += vecEvent.back().tOffPixelIncreasing;







		// std::vector<EventData> vecEvent;
		// pCeleX5->getEventDataVector(vecEvent);
		// cv::Mat matPolarity(800, 1280, CV_8UC1, cv::Scalar::all(128));
		// int dataSize = vecEvent.size();
		// int row = 0, col = 0;
		// for (int i = 0; i < dataSize; i++)
		// {
		// 	row = 799 - vecEvent[i].row;
		// 	col = 1279 - vecEvent[i].col;
		// 	if (vecEvent[i].polarity == 1)
		// 	{
		// 		matPolarity.at<uchar>(row, col) = 255;
		// 	}
		// 	else if (vecEvent[i].polarity == -1)
		// 	{
		// 		matPolarity.at<uchar>(row, col) = 0;
		// 	}
		// 	else
		// 	{
		// 		matPolarity.at<uchar>(row, col) = 128;
		// 	}
		// }
		// if (dataSize > 0)
		// {
		// 	//cout << "size = " << dataSize << ", t = " << vecEvent[dataSize - 1].t - vecEvent[0].t << endl;
		// 	//cout << "count1 = " << count1 << ", count2 = " << count2 << ", count3 = " << count3 << endl;
		// 	cv::imshow("Event Polarity Pic", matPolarity);
		// 	cv::waitKey(1);
		// }
	}
}

int main()
{
	if (pCeleX5 == NULL)
		return 0;
	//pCeleX5->openSensor(CeleX5::CeleX5_MIPI);
	bool success = pCeleX5->openBinFile(BIN_FILE);	//open the bin file
	// CeleX5::CeleX5Mode sensorMode = (CeleX5::CeleX5Mode)pCeleX5->getBinFileAttributes().loopBMode;

	SensorDataObserver* pSensorData = new SensorDataObserver(pCeleX5->getSensorDataServer());
    
    PlaybackState state;
	while (true)
	{
		if (pCeleX5)
		{
			pCeleX5->readBinFileData();	//start reading the bin file
            state = pCeleX5->getPlaybackState();
		}
#ifdef _WIN32
		Sleep(1);
#else
        if(PlayFinished == state)
        {
            break;
        }
		usleep(1000);
#endif
	}
	return 1;
}