#include <iostream>
#include <vector>
#include <cstring>
#include "KThread.h"
#include "Component.h"

using namespace std;

typedef struct kmessage
{
    void* extern_action;
    int   param1;
    int   param2;
    int   param3;
}kmessage;

int main()
{
    {
        Component c;
        {
            Component::Message m(&c, 1000, MESSAGE_SHOW_MYSELF);
            m.post();
        }
        {
            Component::Message m(&c, 1000, MESSAGE_START);
            m.post();
        }
        {
            Component::Message m(&c, 1000, MESSAGE_STOP);
            m.post();
        }
        c.run();
        {
            Component::Message m(&c, 1000, MESSAGE_PLAY);
            m.post();
        }
        {
            Component::Message m(&c, 1000, MESSAGE_PAUSE);
            m.post();
        }
        {
            Component::Message m(&c, 1000, MESSAGE_RESET);
            m.post();
        }
        usleep(10*1000*1000);
    }
    return 0;
}