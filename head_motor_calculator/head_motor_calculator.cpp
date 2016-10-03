#include "../class/ObjPosServer.h"
#include <vector>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <cmath>
#include "../class/MotorCommandGenerator.h"


int main() {
	yarp::os::Network yarp;
	MotorCommandGenerator obj_generator(12344, "/icub_kovan/head_motor_calculator/obj_head_motor_command");
	MotorCommandGenerator head_generator(12345, "/icub_kovan/head_motor_calculator/human_head_motor_command");
	obj_generator.start();
	head_generator.start();

	while(true);
	return 0;
}
