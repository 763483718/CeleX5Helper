/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-03-28 20:51:15
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-07 19:35:47
 */

#include "fileHelper.hpp"
#include "../include/comment.hpp"
#include "RecordEventData.hpp"

int main()
{
    RecordEventData record("../FPN_2.txt");
    // CeleX5* pCeleX5 = record.pCeleX5;
    // record.setLoopMode();
    record.setFixedMode();
    // record.StartRecord("../bin/test.bin");

    
    record.process();

    return 0;
}