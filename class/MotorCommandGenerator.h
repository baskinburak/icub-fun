#include "ObjPosServer.h"
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <vector>
#include <cmath>
#include <unistd.h>

#ifndef MOTOR_COMMAND_GENERATOR
#define MOTOR_COMMAND_GENERATOR

#define PI 3.14159265
#define KAFA_UP_DOWN_MAX 20
#define KAFA_UP_DOWN_MIN -30
#define KAFA_RIGHT_LEFT_MAX 45
#define KAFA_RIGHT_LEFT_MIN -45
#define GOZ_UP_DOWN_MAX 10
#define GOZ_UP_DOWN_MIN -30
#define GOZ_RIGHT_LEFT_MAX 40
#define GOZ_RIGHT_LEFT_MIN -40

class MotorCommandGenerator : public yarp::os::Thread{
	private:
		ObjPosServer pos_server;
		yarp::os::BufferedPort<yarp::os::Bottle> yarp_port;
		yarp::sig::Vector generateHeadMotorPos(std::vector<double> coords);
	public:
		MotorCommandGenerator(int from_netw_port, std::string to_yarp_port);
		void run();
};
#endif
