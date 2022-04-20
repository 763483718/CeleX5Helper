/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-17 14:45:22
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-18 18:26:16
 */

#include "../include/comment.hpp"
#include "RecordEventData-Stereo.hpp"

int main()
{
    RecordEventDataStereo record;
    record.setLoopMode();

    record.process();
    return 0;
}