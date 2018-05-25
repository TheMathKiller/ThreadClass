#ifndef KAUTOLOCK_H
#define KAUTOLOCK_H

#include <pthread.h>

class KAutoLock
{
    public:
        KAutoLock(pthread_mutex_t* lock){
            m = lock;
            pthread_mutex_lock(m);
        }
        ~KAutoLock(){
            pthread_mutex_unlock(m);
            m = NULL;
        }
    private:
        pthread_mutex_t* m;
};

#endif