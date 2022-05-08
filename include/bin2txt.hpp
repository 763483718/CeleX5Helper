/*
 * @Description: celex5拍摄的bin转为txt文件
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-05 23:12:15
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-08 16:05:29
 */
#include <iostream>
#include <fstream>

#include <opencv2/opencv.hpp>
#include "celex5.h"
#include "celex5datamanager.h"
#include "celex5processeddata.h"
#include "fileHelper.hpp"

#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#include<unistd.h>
#endif

class SensorDataObserver : public CeleX5DataManager
{
public:
	SensorDataObserver(CX5SensorDataServer* pServer)
	{
        mFlag = false;
        tick = 0;
        // fOut.open("/home/tuto/code/CeleX5Helper/bin/test.txt", std::ios::trunc | std::ios::in);

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

    int opentxt(string path);
    int closetxt();


private:
    std::ofstream fOut;
    unsigned long long tick;

    bool mFlag;
};