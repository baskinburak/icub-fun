#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <iostream>
#include <vector>
#include <string>
#include<pthread.h>
#ifndef STRING_SERVER
#define STRING_SERVER
class StringServer : public yarp::os::Thread {
	private:
		std::string str;
		int sockfd;
		int portno;
		void startServer(int portno);
		pthread_mutex_t strMutex;
	public:
		StringServer(int p) : yarp::os::Thread(), portno(p) {}
		~StringServer(){}
		void run();
		void onStop();
		void beforeStart();
		void afterStart(bool success);
		bool threadInit();
		void threadRelease();
		std::string getString();
};
#endif
