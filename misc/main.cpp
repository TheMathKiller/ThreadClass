#include <iostream>
#include <vector>
#include <cstring>
#include "KThread.h"

using namespace std;

typedef enum MESSAGE_ID
{
    MESSAGE_START,
    MESSAGE_STOP,
    MESSAGE_PLAY,
    MESSAGE_PAUSE,
    MESSAGE_RESET
}MESSAGE_ID;

typedef struct kmessage
{
    MESSAGE_ID id;
    void* extern_action;
    int   param1;
    int   param2;
    int   param3;
}kmessage;

int main()
{
    {
        thread t;
        t.run();
        usleep(10*1000*1000);
    }
    return 0;
}