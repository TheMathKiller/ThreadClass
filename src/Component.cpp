#include "KThread.h"
#include "Component.h"

int Component::onProcess()
{
    if(mq.size() == 0)
    {
        cout<<"no message..."<<endl;
        usleep(1000*1000);
        return -1;
    }
    else
    {
        Message m = mq[0];
        mq.erase(mq.begin());
        switch(m.getMId()){
            case MESSAGE_SHOW_MYSELF:
                cout<<"MESSAGE_SHOW_MYSELF..."<<endl;
                break;
            case MESSAGE_START:
                cout<<"MESSAGE_START..."<<endl;
                break;
            case MESSAGE_STOP:
                cout<<"MESSAGE_STOP..."<<endl;
                break;
            case MESSAGE_PLAY:
                cout<<"MESSAGE_PLAY..."<<endl;
                break;
            case MESSAGE_PAUSE:
                cout<<"MESSAGE_PAUSE..."<<endl;
                break;
            case MESSAGE_RESET:
                cout<<"MESSAGE_RESET..."<<endl;
                break;
            default:
                cout<<"fuck..."<<endl;
                break;
        }
        cout<<"delay "<<m.delay<<"ms..."<<endl;
        usleep(m.delay*1000);
    }
    return 0;
}

int Component::insertMessage(Message m)
{
    mq.push_back(m);
    return mq.size();
}
