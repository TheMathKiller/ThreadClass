#ifndef KTHREAD_H
#define KTHREAD_H

#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;
typedef void* (*thread_func)(void*);

class thread
{
    public:
        thread();
        ~thread();
        int run();
        void signalExit(){
            pthread_mutex_lock(&Lock);
            exit = 1;
            pthread_mutex_unlock(&Lock);
        }
        int exitThread(){
            int ret = 0;
            pthread_mutex_lock(&Lock);
            ret = (exit != 0);
            pthread_mutex_unlock(&Lock);
            return ret;
        }
        static void* thread_internal(void* ptr);
        virtual int process(int millsecond = 1000){
            usleep(millsecond*1000);
            cout<<"zzzzzz..."<<endl;
            return 0;
        }
    private:
        int exit;
        pthread_t npid;
        pthread_mutex_t Lock;
};

#endif