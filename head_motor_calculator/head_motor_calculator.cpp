#include "../class/ObjPosServer.h"
#include <vector>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <cmath>

#define PI 3.14159265

#define KAFA_UP_DOWN_MAX 20
#define KAFA_UP_DOWN_MIN -30

#define KAFA_RIGHT_LEFT_MAX 45
#define KAFA_RIGHT_LEFT_MIN -45

#define GOZ_UP_DOWN_MAX 10
#define GOZ_UP_DOWN_MIN -30

#define GOZ_RIGHT_LEFT_MAX 40
#define GOZ_RIGHT_LEFT_MIN -40

using namespace std;

yarp::sig::Vector generateHeadMotorPos(std::vector<double> coords) {
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

int main() {
	yarp::os::Network yarp;
	ObjPosServer obj_server(12344);
	obj_server.start();

	ObjPosServer head_server(12345);
	head_server.start();

	yarp::os::BufferedPort<yarp::os::Bottle> obj_port;
	yarp::os::BufferedPort<yarp::os::Bottle> head_port;

	obj_port.open("/icub_kovan/head_motor_calculator/obj_head_motor_command");
	head_port.open("/icub_kovan/head_motor_calculator/human_head_motor_command");

	while(true) {
		// get the data and turn it into motor commands
		yarp::sig::Vector obj_motors = generateHeadMotorPos(obj_server.getObjCoordinates());
		yarp::sig::Vector head_motors = generateHeadMotorPos(head_server.getObjCoordinates());

		yarp::os::Bottle& obj_bottle = obj_port.prepare();
		obj_bottle.clear();
		for(int i=0; i<6; i++) {
			obj_bottle.addDouble(obj_motors[i]);
		}
		obj_port.write();

		yarp::os::Bottle& head_bottle = head_port.prepare();
		head_bottle.clear();
		for(int i=0; i<6; i++) {
			head_bottle.addDouble(head_motors[i]);
		}
		head_port.write();
	}
}
