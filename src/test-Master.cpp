/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-28 21:28:28
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-29 20:00:24
 */

#include <iostream>
#include <string>
#include "SocketHelper.hpp"
using namespace std;
int main()
{
    string ip = "10.12.41.81";
    int port = 8081;

    ClientHelper* client = new ClientHelper();
    int fd1 = client->connection(ip, port);
    int fd2 = client->connection("127.0.0.1", 8081);
    // ClientHelper* client2 = new ClientHelper();
    // int fd2 = client2->connection("127.0.0.1", 8081);

while(1)
    {
        // cout << "please input data\n";

        string data;cin >> data;


        client->sendData(fd1, data.c_str(), data.size());
        client->sendData(fd2, data.c_str(), data.size());
    }

    return 0;
}