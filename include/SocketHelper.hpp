/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-20 23:12:45
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-04-25 22:34:05
 */

#include<stdio.h>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<sys/fcntl.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<errno.h>
#include<sys/types.h>
#include <arpa/inet.h>
using namespace std;

#include <string>
#include <vector>
#include <mutex>
#include "RecordEventData.hpp"

class SocketHelper
{
public:
    SocketHelper(){}
    SocketHelper(int port):mPort(port){}
    SocketHelper(string ip, int port):mPort(port), mIp(ip){}
    
    virtual ~SocketHelper(){}
protected:
    int mPort;
    string mIp;
};

class ClientHelper : SocketHelper
{
public:
    ClientHelper(){}
    ClientHelper(string ip, int port):SocketHelper(ip, port){}
    int connection();
    int connection(string ip, int port);
    int sendData(const char* buffer, int size);
    int sendData(int index, const char* buffer, int size);
    int disconnect(string ip, int port);
    
    ~ClientHelper();
private:
    int connectionSerive(sockaddr_in &servaddr, int &sockfd);
    int sendDataSerive(sockaddr_in addr, const char* buffer, int size);

    int mSockfd;

    vector<int> mVecPort;
    vector<string> mVecIp;
    vector<struct sockaddr_in> mVecAddr;
    struct sockaddr_in mAddr;

    std::mutex mMtxModify;
};

class ServerHelper : SocketHelper
{
public:
    ServerHelper(){}
    ServerHelper(int port):SocketHelper(port){}
    int listenAndReceive();

    int bindCallback(RecordEventData* r);
private:
    int mListenfd;
    int mClintfd;

    RecordEventData* pRecordEventData;
};


// std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);

