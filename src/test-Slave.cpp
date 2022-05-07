/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-28 21:28:15
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-03 20:52:55
 */

#include <iostream>
#include <string>
#include "SocketHelper.hpp"
using namespace std;

int main(int argc,char *argv[])
{
    int port = 8081;
    ServerHelper* sv = new ServerHelper(port);

    sv->listenAndReceive_test();
    
    return 0;
}
