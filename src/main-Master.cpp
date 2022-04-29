/*
 * @Description: 主机主程序（客户端）
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-20 23:13:28
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-25 23:47:44
 */
#include <iostream>
#include <string>
#include "SocketHelper.hpp"
using namespace std;
int main(int argc,char *argv[])
{
    string ip;int port;
    cout << "please input ip and port\n";
    cin >> ip >> port;
    
    ClientHelper* client = new ClientHelper();
    int fd1 = client->connection(ip, port);
    int fd2 = client->connection("127.0.0.1", 8081);

    cout << "fd1:\t" << fd1 << "\tfd2:\t" << fd2 << endl;

    int actionNo, personNo;
    char c;
    while(1)
    {
        cout << "please input actionNo and personNo\n";
        cin >> actionNo >> personNo;
        string data = "b";
        if(actionNo < 10)
        {
            data += "0";
        }
        data += std::to_string(actionNo);
        
        if(personNo < 10)
        {
            data += "0";
        }
        data += std::to_string(personNo);

        client->sendData(fd1, data.c_str(), data.size());
        client->sendData(fd2, data.c_str(), data.size());

        while(cin >> c)
        {
            if(c == 'e')
            {
                client->sendData(fd1, "e", 1);
                client->sendData(fd2, "e", 1);
                break;
            }
        }
    }
}
