/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-05-01 18:03:21
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-01 19:39:46
 */
#include <opencv2/opencv.hpp>
#include "celex5.h"
#include "celex5datamanager.h"

#ifdef _WIN32
#include <windows.h>
#else
#include<unistd.h>
#include <signal.h>
#endif

using namespace std;
using namespace cv;

class SensorDataObserver : public CeleX5DataManager
{
public:
    SensorDataObserver(CX5SensorDataServer* pServer);
    ~SensorDataObserver();
    virtual void onFrameDataUpdated(CeleX5ProcessedData* pSensorData);

private:
    CX5SensorDataServer* m_pServer;
    CeleX5* pCeleX5;
};