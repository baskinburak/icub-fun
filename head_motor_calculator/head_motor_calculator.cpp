#include "../class/ObjPosServer.h"
#include <vector>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <cmath>
#include "../class/MotorCommandGenerator.h"


int main() {
	yarp::os::Network yarp;
	MotorCommandGenerator obj1_generator(15001, "/icub_kovan/head_motor_calculator/obj1_head_motor_command");
	MotorCommandGenerator obj2_generator(15002, "/icub_kovan/head_motor_calculator/obj2_head_motor_command");
	MotorCommandGenerator obj3_generator(15003, "/icub_kovan/head_motor_calculator/obj3_head_motor_command");
	MotorCommandGenerator gaze1_generator(15007, "/icub_kovan/head_motor_calculator/gaze1_head_motor_command");
	MotorCommandGenerator gaze2_generator(15008, "/icub_kovan/head_motor_calculator/gaze2_head_motor_command");
	MotorCommandGenerator human_head_generator(17108, "/icub_kovan/head_motor_calculator/human_head_motor_command");
	MotorCommandGenerator hand_generator(17105, "/icub_kovan/head_motor_calculator/hand_head_motor_command");
	

	gaze1_generator.start();
	gaze2_generator.start();
	hand_generator.start();
	human_head_generator.start();
	obj3_generator.start();
	obj2_generator.start();
	obj1_generator.start();
	
	yarp::os::Network::connect("/icub_kovan/head_motor_calculator/obj1_head_motor_command", "/icub_kovan/action_selector/obj1_head_motor_command");
	yarp::os::Network::connect("/icub_kovan/head_motor_calculator/obj2_head_motor_command", "/icub_kovan/action_selector/obj2_head_motor_command");
	yarp::os::Network::connect("/icub_kovan/head_motor_calculator/obj3_head_motor_command", "/icub_kovan/action_selector/obj3_head_motor_command");
	yarp::os::Network::connect("/icub_kovan/head_motor_calculator/gaze1_head_motor_command", "/icub_kovan/action_selector/gaze1_head_motor_command");
	yarp::os::Network::connect("/icub_kovan/head_motor_calculator/gaze2_head_motor_command", "/icub_kovan/action_selector/gaze2_head_motor_command");
	yarp::os::Network::connect("/icub_kovan/head_motor_calculator/human_head_motor_command", "/icub_kovan/action_selector/human_head_motor_command");
	yarp::os::Network::connect("/icub_kovan/head_motor_calculator/hand_head_motor_command", "/icub_kovan/action_selector/hand_head_motor_command");

	gaze1_generator.join();
	gaze2_generator.join();
	hand_generator.join();
	human_head_generator.join();
	obj3_generator.join();
	obj2_generator.join();
	obj1_generator.join();

	return 0;
}	
