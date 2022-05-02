/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-05-02 15:24:27
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-02 17:56:02
 */
#include <pthread.h> 

class Thread
{
public:
    Thread();
    int start();
    pthread_t getPid();

    virtual int close() = 0; //修改m_isRunning、释放线程及资源
    virtual void fpConnectionRunning() = 0;
private:
    static void * start_thread(void *arg)
    {
        Thread *ptr = (Thread *)arg;
        ptr->m_isRunning = 1;
        ptr->fpConnectionRunning();  //线程的实体是run
    }
private:
    pthread_t mPid;
protected:
    bool m_isRunning;
};