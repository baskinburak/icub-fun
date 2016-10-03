#include <iostream>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include "../class/YarpPortReader.h"
#include <vector>
#include "../class/MotorController.h"
#include <gsl/gsl_math.h>
#include <unistd.h>

void arm_move(MotorController* sim, MotorController* icub) {
	
	std::vector<double> vect;
	vect.resize(16);
	vect[0]=-48.2991;
	vect[1]=70.7504;
	vect[2]=0.000272427;
	vect[3]=50.0003;
	vect[4]=2.8192e-05;
	vect[5]=5.66584e-06;
	vect[6]=6.42255e-06;
	vect[7]=59.001;
	vect[8]=20.0003;
	vect[9]=20.0003;
	vect[10]=20.0003;
	vect[11]=10.0002;
	vect[12]=10.0002;
	vect[13]=10.0002;
	vect[14]=10.0002;
	vect[15]=10.0002;
	
	icub->sendCommand(vect);sleep(2);
	
	vect[0]=-32.5484;
	vect[1]=30.5509;
	vect[2]=4.68021;
	vect[3]=50.0002;
	vect[4]=3.54488e-05;
	vect[5]=2.9109e-06;
	vect[6]=8.50143e-06;
	vect[7]=59.001;
	vect[8]=20.0003;
	vect[9]=20.0003;
	vect[10]=20.0003;
	vect[11]=10.0002;
	vect[12]=10.0002;
	vect[13]=10.0002;
	vect[14]=10.0002;
	vect[15]=10.0002;
	
	icub->sendCommand(vect);sleep(2);
	
	vect[0]=-35.6981;
	vect[1]=14.4717;
	vect[2]=32.7603;
	vect[3]=64.2543;
	vect[4]=-25.2;
	vect[5]=-1.51008e-07;
	vect[6]=8.89084e-06;
	vect[7]=59.001;
	vect[8]=20.0003;
	vect[9]=20.0003;
	vect[10]=20.0003;
	vect[11]=10.0002;
	vect[12]=10.0002;
	vect[13]=10.0002;
	vect[14]=10.0002;
	vect[15]=10.0002;
	
	icub->sendCommand(vect);
	
}

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
		std::cout << "[ERR] Connecting to icubSim failed" << std::endl;
		std::cout << e << std::endl;
	}

	bool icub_on = false;

	try {
		head_controller = new MotorController("icub", "head", 10, 10);
		right_arm_controller = new MotorController("icub", "right_arm", 10, 10);
		icub_on = true;
		std::cout << "[SCC] Connected to icub" << std::endl;
	} catch(std::string e) {
		std::cout << "[ERR] Connecting to icub failed" << std::endl;
		std::cout << e << std::endl;
	}

	while(true) {
		std::vector<double> head_mc = head_command.getData();
		std::vector<double> obj_mc = obj_command.getData();
		std::vector<double> arm_mc = arm_command.getData();


		int action;
		std::cout << "select action (1 - move arm, 2 - look at object, 3 - look at human head)" << std::endl;
		std::cin >> action;

		switch(action) {
			case 1:
				arm_move(sim_right_arm_controller, right_arm_controller);
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
