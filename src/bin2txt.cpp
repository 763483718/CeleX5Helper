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


#include "bin2txt.hpp"

#define FPN_PATH    "../Samples/config/FPN_2.txt"
//#define BIN_FILE    "YOUR_BIN_FILE_PATH.bin"	//your bin file path
#define BIN_FILE    "/home/tuto/code/CeleX5Helper/bin/dataset/00/00/0.bin"	//your bin file path

CeleX5 *pCeleX5 = new CeleX5;



uint8_t * pImageBuffer = new uint8_t[CELEX5_PIXELS_NUMBER];
void SensorDataObserver::onFrameDataUpdated(CeleX5ProcessedData* pSensorData)
{
	if (NULL == pSensorData)
		return;
	CeleX5::CeleX5Mode sensorMode = pSensorData->getSensorMode();
	if (CeleX5::Full_Picture_Mode == sensorMode)
	{
        return;
		//full-frame picture
		pCeleX5->getFullPicBuffer(pImageBuffer);
		cv::Mat matFullPic(800, 1280, CV_8UC1, pImageBuffer);
		cv::imshow("FullPic", matFullPic);
		cv::waitKey(1);
	}
	else if (CeleX5::Event_Off_Pixel_Timestamp_Mode == sensorMode)
	{
		//get buffers when sensor works in EventMode
        return;
		pCeleX5->getEventPicBuffer(pImageBuffer, CeleX5::EventBinaryPic);
		cv::Mat matEventPic(800, 1280, CV_8UC1, pImageBuffer);
		cv::imshow("Event Binary Pic", matEventPic);
		cvWaitKey(1);
	}
	else if (CeleX5::Optical_Flow_Mode == sensorMode)
	{
		//full-frame optical-flow pic
        return;
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
            mFlag = true;
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
	}
}

int SensorDataObserver::opentxt(string path)
{
    closetxt();
    fOut.open(path, std::ios::trunc | std::ios::in);
    return true;
}

int SensorDataObserver::closetxt()
{
    if(fOut.is_open())
    {
        fOut.close();
    }
    if(mFlag)
    {
        mFlag = false;
        return true;
    }
    return false;
}

void read(string binFile)
{
    //pCeleX5->openSensor(CeleX5::CeleX5_MIPI);
	bool success = pCeleX5->openBinFile(binFile);	//open the bin file
	// CeleX5::CeleX5Mode sensorMode = (CeleX5::CeleX5Mode)pCeleX5->getBinFileAttributes().loopBMode;


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
}

int main()
{
	if (pCeleX5 == NULL)
		return 0;

	SensorDataObserver* pSensorData = new SensorDataObserver(pCeleX5->getSensorDataServer());
    

    // string path = "/home/server/Desktop/cgz/CeleX5Helper/bin/dataset/";
    // string path = "/home/tuto/code/CeleX5Helper/bin/dataset";
    string path = "../bin/dataset";
    vector<string> filenames, actFolderNames;
    vector<string> nullvec;
    getFiles(path, nullvec, actFolderNames);
    
    string actPath;
    vector<string> personFolderNames;
    
    
    for(auto &actName : actFolderNames)
    {
        int count = 0;
        string txtFolder = path + "txt/";
        txtFolder += actName;
        txtFolder += "/";
        makeFolder(txtFolder);


        actPath = path;
        actPath += "/";
        actPath += actName;

        string personPath;
        getFiles(actPath, nullvec, personFolderNames);
        for(auto &personName : personFolderNames)
        {
            personPath = actPath;
            personPath += "/";
            personPath += personName;

            filenames.clear();
            string itemPath;
            getFiles(personPath, filenames, nullvec);
            for(auto &itemName : filenames)
            {
                itemPath = personPath;
                itemPath += "/";
                itemPath += itemName;
                
                
                if(pSensorData->closetxt())
                {
                    ++count;
                }
                string txtfile = txtFolder + std::to_string(count) + ".txt";
                pSensorData->opentxt(txtfile);

                read(itemPath);
            }
        }

    }



	return 1;
}