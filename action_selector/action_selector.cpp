#include <iostream>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include "../class/YarpPortReader.h"
#include <vector>
#include "../class/MotorController.h"

int main() {
	yarp::os::Network yarp;
	YarpPortReader head_command("/icub_kovan/action_selector/human_head_motor_command");
	YarpPortReader obj_command("/icub_kovan/action_selector/obj_head_motor_command");
	YarpPortReader arm_command("/icub_kovan/action_selector/obj_arm_motor_command");

	bool icub_sim_on = false;

	MotorController* sim_head_controller;
	MotorController* sim_right_arm_controller;
	MotorController* head_controller;
	MotorController* right_arm_controller;

	try {
		sim_head_controller = new MotorController("icubSim", "head", 10, 10);
		sim_right_arm_controller = new MotorController("icubSim", "right_arm", 10, 10);
		icub_sim_on = true;
		std::cout << "[SCC] Connected to icubSim" << std::endl;
	} catch (std::string e) {
		std::cout << e << std::endl;
	}

	bool icub_on = false;

	try {
		head_controller = new MotorController("icub", "head", 10, 10);
		right_arm_controller = new MotorController("icub", "right_arm", 10, 10);
		icub_on = true;
		std::cout << "[SCC] Connected to icub" << std::endl;
	} catch(std::string e) {
		std::cout << e << std::endl;
	}

	while(true) {
		std::vector<double> head_mc = head_command.getData();
		std::vector<double> obj_mc = obj_command.getData();
		std::vector<double> arm_mc = arm_command.getData();

		int action;
		std::cout << "select action (1 - move arm, 2 - look at object, 3 - look at human head)" << std::endl;

		switch(action) {
			case 1:
				if(icub_sim_on)
					sim_right_arm_controller->sendCommand(arm_mc);
				if(icub_on)
					right_arm_controller->sendCommand(arm_mc);
				break;
			case 2:
				if(icub_sim_on)
					sim_head_controller->sendCommand(obj_mc);
				if(icub_on)
					head_controller->sendCommand(obj_mc);
				break;
			case 3:
				if(icub_sim_on)
					sim_head_controller->sendCommand(head_mc);
				if(icub_on)
					head_controller->sendCommand(head_mc);
				break;
		} 	
	}
	
}
