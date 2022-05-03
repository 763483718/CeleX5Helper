#include "imshowHelper.hpp"

imshowHelper::imshowHelper()
{
    mWaitTime = 10;
}

void imshowHelper::addImage(string name, cv::Mat img)
{
    std::lock_guard<std::mutex> lck(mMtx,std::adopt_lock);
    mMap[name] = pair<cv::Mat, int>(img, 10);
}

int imshowHelper::close()
{
    m_isRunning = true;
}

void imshowHelper::fpConnectionRunning()
{
    cout << __func__ << ":\t start============\n";
    vector<string> names;
    while(m_isRunning)
    {
        std::lock_guard<std::mutex> lck(mMtx,std::adopt_lock);
        for(auto &item : mMap)
        {
            if(item.second.second != mWaitTime)
            {
                cv::imshow(item.first, item.second.first);
            }
            --item.second.second;
            if(item.second.second < 0)
            {
                names.emplace_back(item.first);
            }
        }
        cv::waitKey(10);
        for(auto &name : names)
        {
            mMap.erase(name);
        }
        names.clear();
    }
}