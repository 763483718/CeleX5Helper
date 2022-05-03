#include "comment.hpp"
#include "thread.hpp"
#include <unordered_map>
#include <vector>
#include <mutex>
using namespace std;

class imshowHelper : public Thread
{
public:
    imshowHelper();
    void addImage(string name, cv::Mat img);
    int close();
    void fpConnectionRunning();
private:
    unordered_map<string, std::pair<cv::Mat, int>> mMap;

    int mWaitTime;

    mutex mMtx;
};