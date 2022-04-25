/*
 * @Description: 从机主程序(服务端)
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-20 23:13:40
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-25 19:32:07
 */


#include <iostream>
#include <string>
#include "SocketHelper.hpp"
#include "../include/comment.hpp"
#include "RecordEventData.hpp"

using namespace std;

int main(int argc,char *argv[])
{
    int port;
    cout << "please input port\n";
    cin >> port;
    ServerHelper* sv = new ServerHelper(port);

    RecordEventData *record = new RecordEventData("../FPN_2.txt");
    
    if(*argv[1] == 'f')
    {
        record->setFixedMode();
    }else
    {
        record->setLoopMode();
    }

    sv->bindCallback(record);

    sv->listenAndReceive();
    
    return 0;
}
