#ifndef KTHREAD_H
#define KTHREAD_H

#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include "KAutolock.h"

using namespace std;
typedef void* (*thread_func)(void*);

class thread
{
    public:
        thread();
        ~thread();
        int run();
        void signalExit();
        int exitThread();
        static void* thread_internal(void* ptr);
        virtual int onProcess()= 0;
        pthread_mutex_t Lock;
    private:
        int exit;
        pthread_t npid;
};

#endif