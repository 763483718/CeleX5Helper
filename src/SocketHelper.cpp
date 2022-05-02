/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-04-20 23:13:06
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-01 20:40:59
 */

#include "SocketHelper.hpp"

ClientHelper::~ClientHelper()
{
    close(mSockfd);
    // for(auto &item : mVecSockfd)
    // {
    //     close(item);
    // }
}

int ClientHelper::connection()
{
    memset(&mAddr,0,sizeof(mAddr));
    mAddr.sin_family = AF_INET;

    mAddr.sin_port = htons(mPort); // server's port
    mAddr.sin_addr.s_addr=inet_addr(mIp.c_str());//server's ip

    connectionSerive(mAddr, mSockfd);
}

int ClientHelper::connection(string ip, int port)
{
    struct sockaddr_in servaddr;
    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port); // server's port
    servaddr.sin_addr.s_addr=inet_addr(ip.c_str());//server's i

    int sockfd = -1;
    int ret = connectionSerive(servaddr, sockfd);
    if(ret == 1)
    {
        std::lock_guard<std::mutex> lck(mMtxModify, std::adopt_lock);
        mVecPort.emplace_back(port);
        mVecIp.emplace_back(ip);
        mVecSockfd.emplace_back(sockfd);
        // mVecAddr.emplace_back(servaddr);
    }
    // return mVecAddr.size() - 1;
    return mVecSockfd.size() - 1;
}

int ClientHelper::disconnect(string ip, int port)
{
    std::lock_guard<std::mutex> lck(mMtxModify, std::adopt_lock);
    
    for(int i = 0; i < mVecIp.size(); ++i)
    {
        if(mVecIp[i] == ip)
        {
            mVecPort[i] = mVecPort.back();
            mVecIp[i] = mVecIp.back();
            // mVecAddr[i] = mVecAddr.back();
            close(mVecSockfd[i]);
            mVecSockfd[i] = mVecSockfd.back();

            mVecPort.pop_back();
            mVecIp.pop_back();
            mVecSockfd.pop_back();
            break;
        }
    }

}

int ClientHelper::connectionSerive(sockaddr_in &servaddr,int &sockfd)
{
    if(sockfd == -1)
    {
        if ( (sockfd = socket(AF_INET,SOCK_STREAM,0))==-1) 
        { 
            perror("socket"); 
            return -1; 
        }
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) != 0)
    { 
        perror("connect"); 
        close(sockfd); 
        return -1; 
    }
    return 1;
}

int ClientHelper::sendData(const char* buffer, int size)
{
    return sendDataSerive(mSockfd, buffer, size);
}

int ClientHelper::sendData(int index, const char* buffer, int size)
{
    if(index < 0)
    {
        return -1;
    }
    return sendDataSerive(mVecSockfd[index], buffer, size);
}

int ClientHelper::sendDataSerive(int sockfd, const char* buffer, int size)
{
    int iret;
    if ( (iret=send(sockfd,buffer,size,0))<=0) // send data to server
    { 
        perror("send"); 
        return -1;
    }
    char recvBuff[128];
    if ( (iret=recv(sockfd,recvBuff,sizeof(recvBuff),0))<=0)
    {
        printf("iret=%d\n", iret); 
        return -1;
    }
    printf("receive: %s\n",recvBuff);
    return 1;
}

int ServerHelper::listenAndReceive()
{
    mListenfd = socket(AF_INET, SOCK_STREAM, 0);

    if(mListenfd == -1)
    {
        printf("socket create fail\n");
        return -1;
    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    serveraddr.sin_port=htons(mPort);
    if(bind(mListenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))!=0)
    {
        printf("bind failed \n");
        return -1;
    }

    if(listen(mListenfd,5)!=0)
    {
        printf("Listen failed\n");
        close(mListenfd);
        return -1;
    }

    int socklen=sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;
    mClintfd=accept(mListenfd,(struct sockaddr*)&client_addr,(socklen_t *)&socklen);
    if(mClintfd==-1)
        printf("connect failed\n");
    else
        printf("client %s has connnected\n",inet_ntoa(client_addr.sin_addr));

    char buffer[1024];
    while(1)
    {
        int iret;
        memset(buffer,0,sizeof(buffer));
        iret=recv(mClintfd,buffer,sizeof(buffer),0);
        if (iret<=0) 
        {
            printf("iret=%d\n",iret); break;  
        }
        //cout <<"buffer:\t"<< string(buffer) << endl;
        string buf(buffer);
        if(buffer[0] == 'b')
        {
            string actionNo;
            string personNo;
            actionNo = buf.substr(1,2);
            personNo = buf.substr(3,2);
            //memcpy(actionNo, &(buffer[1]), 2);
            //memcpy(personNo, &(buffer[3]), 2);
            pRecordEventData->takeAVideo(atoi(actionNo.c_str()), atoi(personNo.c_str()));
        }else if(buffer[0] == 'e')
        {
            pRecordEventData->StopRecord();
        }
        else
        {
            break;
        }
        
        strcpy(buffer,"ok");//reply cilent with "ok"
        if ( (iret=send(mClintfd,buffer,strlen(buffer),0))<=0) 
        { 
            perror("send"); 
            break; 
        }
        printf("send :%s\n",buffer);
    }
    close(mListenfd); close(mClintfd);
}

int ServerHelper::bindCallback(RecordEventData* r)
{
    pRecordEventData = r;
}

int ServerHelper::listenAndReceive_test()
{
    mListenfd = socket(AF_INET,SOCK_STREAM,0);

    if(mListenfd == -1)
    {
        printf("socket create fail\n");
        return -1;
    }
    struct sockaddr_in serveraddr;
    memset(&serveraddr,0,sizeof(serveraddr));
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    serveraddr.sin_port=htons(mPort);
    if(bind(mListenfd,(struct sockaddr *)&serveraddr,sizeof(serveraddr))!=0)
    {
        printf("bind failed \n");
        return -1;
    }

    if(listen(mListenfd,5)!=0)
    {
        printf("Listen failed\n");
        close(mListenfd);
        return -1;
    }

    int socklen=sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;
    mClintfd=accept(mListenfd,(struct sockaddr*)&client_addr,(socklen_t *)&socklen);
    if(mClintfd==-1)
        printf("connect failed\n");
    else
        printf("client %s has connnected\n",inet_ntoa(client_addr.sin_addr));

    char buffer[1024];
    while(1)
    {
        int iret;
        memset(buffer,0,sizeof(buffer));
        iret=recv(mClintfd,buffer,sizeof(buffer),0);
        if (iret<=0) 
        {
            printf("iret=%d\n",iret); break;  
        }
        string out(buffer);
        cout << "recv:\t" << out << endl;
        
        strcpy(buffer,"ok");//reply cilent with "ok"
        if ( (iret=send(mClintfd,buffer,strlen(buffer),0))<=0) 
        { 
            perror("send"); 
            break; 
        }
        printf("send :%s\n",buffer);
    }
    close(mListenfd); close(mClintfd);
}
