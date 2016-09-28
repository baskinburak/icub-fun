#include "MotorController.h"

MotorController::MotorController(std::string robot_name, std::string robot_part, int ref_acc, int ref_speed) {
	if(robot_name != "icub" && robot_name != "icubSim") {
		throw std::string("robot_name must be icub or icubSim");
	}

	if(robot_part != "head" && robot_part != "right_arm" && robot_part != "left_arm" && robot_part != "left_leg" && robot_part != "right_leg" && robot_part != "torso") {
		throw std::string("robot_part must be head, right_arm, left_arm, left_leg, right_leg or torso");
	}

	(this->options).put("device", "remote_controlboard");
	(this->options).put("robot", robot_name.c_str());
	(this->options).put("local", "/icub_kovan/client");
	std::string remote = std::string("/") + robot_name + std::string("/") + robot_part;
	(this->options).put("remote", remote.c_str());

	this->driver = new yarp::dev::PolyDriver(this->options);

	if(!((this->driver)->isValid())) {
		throw (std::string("cannot connect to driver ") + remote);
	}

	(this->driver)->view(this->pos);
	(this->driver)->view(this->vel);
	(this->driver)->view(this->enc);

	if(pos == NULL || vel == NULL || enc == NULL) {
		(this->driver)->close();
		throw (std::string("cannot get interface to driver ") + remote);
	}

	pos->getAxes(&(this->jnts));

	yarp::sig::Vector tmp;
	tmp.resize(this->jnts);

	for(int i=0; i<this->jnts; i++) {
		tmp[i] = ref_acc;
	}
	pos->setRefAccelerations(tmp.data());

	for(int i=0; i<this->jnts; i++) {
		tmp[i] = ref_speed;
	}
	pos->setRefSpeeds(tmp.data());
}

void MotorController::sendCommand(std::vector<double> command) {
	if(command.size() != this->jnts) {
		std::cout << "[ERR] motor command size does not match joint size" << std::endl;
		return;
	}

	yarp::sig::Vector motors;
	motors.resize(this->jnts);
	for(int i=0; i<this->jnts; i++) {
		motors[i] = command[i];
	}

	bool ok = pos->positionMove(motors.data());
	if(ok) {
		std::cout << "[SCC] motor command sent." << std::endl;
	} else {
		std::cout << "[ERR] motor command failed to send." << std::endl;
	}
}
