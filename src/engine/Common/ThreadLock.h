#ifndef __THREAD_LOCK_H__
#define __THREAD_LOCK_H__

#include <pthread.h>

class MyCThreadLock  
{
public:
    MyCThreadLock();
    virtual ~MyCThreadLock();

    void Lock();
    void Unlock();
private:
    pthread_mutex_t mutexlock;
};

#endif //__THREAD_LOCK_H__