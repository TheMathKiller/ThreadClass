#include <iostream>
#include <cstring>
#include "KThread.h"

using namespace std;

thread::thread()
{
    cout<<"begin"<<endl;
    exit = 0;
    npid = 0;
    pthread_mutex_init(&Lock, NULL);
}

thread::~thread()
{
    void *status;
    signalExit();
    cout<<"end1"<<endl;
    pthread_join(npid, &status);
    cout<<"end2"<<endl;
    pthread_mutex_destroy(&Lock);
}

void* thread::thread_internal(void* user)
{
    thread* const self = static_cast<thread*>(user);
    while(!self->exitThread())
    {
        self->process();
    }
    return NULL;
}

int thread::run()
{
    int ret = 0;
    ret=pthread_create(&npid, NULL, thread::thread_internal, this);
    if(ret)
    {
        cout<<"create pthread error!"<<endl;
        return -1; 
    }
    return 0;
}