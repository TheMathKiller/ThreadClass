#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>

typedef enum For_what {
		MESSAGE_SHOW_MYSELF,
		MESSAGE_START,
		MESSAGE_STOP,
		MESSAGE_PLAY,
		MESSAGE_PAUSE,
		MESSAGE_RESET
}For_what;

class Component : public thread
{
	public:
		class Message
		{
			public:
				Message(Component* t = NULL, int d = 0, For_what fw = MESSAGE_SHOW_MYSELF):c(t), delay(d), mId(fw){}
				~Message(){}
				void post(){
					if(c != NULL)
						c->insertMessage(*this);
				}
				For_what getMId(){
					return mId;
				}
				int delay;
			private:
				For_what mId;
				Component* c;
		};
		virtual int onProcess();
		int insertMessage(Message m);
	private:
		vector<Message> mq;
};

#endif

