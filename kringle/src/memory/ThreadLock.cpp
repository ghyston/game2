#include "ThreadLock.h"

MyCThreadLock::MyCThreadLock()
{
    // init lock here
    pthread_mutex_init(&mutexlock, 0);
}

MyCThreadLock::~MyCThreadLock()
{
    // deinit lock here
    pthread_mutex_destroy(&mutexlock);
}
void MyCThreadLock::Lock()
{
    // lock
    pthread_mutex_lock(&mutexlock);
}
void MyCThreadLock::Unlock()
{
    // unlock
    pthread_mutex_unlock(&mutexlock);
}
