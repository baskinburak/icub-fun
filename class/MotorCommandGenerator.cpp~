#include "MotorCommandGenerator.h"

MotorCommandGenerator::MotorCommandGenerator(int netw_port, std::string y_port) : pos_server(netw_port) {
	(this->yarp_port).open(y_port);
}

void MotorCommandGenerator::run() {
	(this->pos_server).start();
	while(true) {
		yarp::sig::Vector motors = (this->generateHeadMotorPos)((this->pos_server).getObjCoordinates());
		yarp::os::Bottle& bottle = (this->yarp_port).prepare();
		bottle.clear();
		for(int i=0; i<motors.size(); i++) {
			bottle.addDouble(motors[i]);
		}
		(this->yarp_port).write();
		usleep(1000*1000*0.5); // 0.5 sec delay
	}
}

yarp::sig::Vector MotorCommandGenerator::generateHeadMotorPos(std::vector<double> coords) {
	yarp::sig::Vector motors;
	motors.resize(6);
	for(int i=0; i<6; i++) {
		motors[i] = 0.0;
	}

	double ud = std::asin(coords[2]/(std::sqrt(coords[0]*coords[0]+coords[1]*coords[1]+coords[2]*coords[2]))) * 180.0 / PI;
	double rl = std::asin(coords[1]/(std::sqrt(coords[0]*coords[0]+coords[1]*coords[1]))) * 180.0 / PI;

	if(ud != ud || rl != rl) {
		return motors;
	}

	if(ud>0) {
		if(ud>GOZ_UP_DOWN_MAX) {
			motors[3] = GOZ_UP_DOWN_MAX;
			ud-=GOZ_UP_DOWN_MAX;
			if(ud>KAFA_UP_DOWN_MAX) {
				motors[0] = KAFA_UP_DOWN_MAX;
			} else {
				motors[0] = ud;
			}
		} else {
			motors[3] = ud;
		}
	} else {
		if(ud<GOZ_UP_DOWN_MIN) {
			motors[3] = GOZ_UP_DOWN_MIN;
			ud-=GOZ_UP_DOWN_MIN;
			if(ud<KAFA_UP_DOWN_MIN) {
				motors[0] = KAFA_UP_DOWN_MIN;
			} else {
				motors[0] = KAFA_UP_DOWN_MIN;
			}
		} else {
			motors[3] = ud;
		}
	}

	if(rl>0) {
		if(rl>GOZ_RIGHT_LEFT_MAX) {
			motors[4] = -GOZ_RIGHT_LEFT_MAX;
			rl-=GOZ_RIGHT_LEFT_MAX;
			if(rl > KAFA_RIGHT_LEFT_MAX) {
				motors[2] = KAFA_RIGHT_LEFT_MAX;
			} else {
				motors[2] = rl;
			}
		} else {
			motors[4] = -rl;
		}
	} else {
		if(rl<GOZ_RIGHT_LEFT_MIN) {
			motors[4] = -GOZ_RIGHT_LEFT_MIN;
			rl-=GOZ_RIGHT_LEFT_MIN;
			if(rl < KAFA_RIGHT_LEFT_MIN) {
				motors[2] = KAFA_RIGHT_LEFT_MIN;
			} else {
				motors[2] = rl;
			}
		} else {
			motors[4] = -rl;
		}
	}
	return motors;
}
