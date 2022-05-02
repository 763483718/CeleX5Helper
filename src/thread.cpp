/*
 * @Description: 
 * @Version: 
 * @Autor: guanzhou
 * @email: guanzhou.cn@gmail.com
 * @Date: 2022-05-02 15:24:15
 * @LastEditors: guanzhou
 * @LastEditTime: 2022-05-02 18:08:41
 */

#include "thread.hpp"

Thread::Thread()
{
    m_isRunning = false;
}

int Thread::start()
{
    m_isRunning = true;
    if(pthread_create(&mPid, NULL, start_thread, (void *)this) != 0)
    {
        m_isRunning = false;
        return -1;
    }
    return 1;
}

pthread_t Thread::getPid()
{
    return mPid;
}
