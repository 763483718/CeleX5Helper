/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-05-01 18:02:57
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-01 19:21:20
 */
#include "SensorDataObserver.hpp"

SensorDataObserver::SensorDataObserver(CX5SensorDataServer* pServer)
{
    m_pServer = pServer;
    m_pServer->registerData(this, CeleX5DataManager::CeleX_Frame_Data);
}

SensorDataObserver::~SensorDataObserver()
{
		m_pServer->unregisterData(this, CeleX5DataManager::CeleX_Frame_Data);
}

void SensorDataObserver::onFrameDataUpdated(CeleX5ProcessedData* pSensorData)
{
	if (NULL == pSensorData)
		return;
	if (CeleX5::Event_Intensity_Mode == pSensorData->getSensorMode())
	{
		std::vector<EventData> vecEvent;
		pCeleX5->getEventDataVector(vecEvent);
		cv::Mat matPolarity(800, 1280, CV_8UC1, cv::Scalar::all(128));
		int dataSize = vecEvent.size();
		int row = 0, col = 0;
		for (int i = 0; i < dataSize; i++)
		{
			row = 799 - vecEvent[i].row;
			col = 1279 - vecEvent[i].col;
			if (vecEvent[i].polarity == 1)
			{
				matPolarity.at<uchar>(row, col) = 255;
			}
			else if (vecEvent[i].polarity == -1)
			{
				matPolarity.at<uchar>(row, col) = 0;
			}
			else
			{
				matPolarity.at<uchar>(row, col) = 128;
			}
		}
		if (dataSize > 0)
		{
			cv::imshow("Event Polarity Pic", matPolarity);
			cv::waitKey(1);
		}
	}
}

