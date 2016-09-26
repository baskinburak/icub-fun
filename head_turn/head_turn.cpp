#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <iostream>
#include <cmath>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sstream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define PI 3.14159265

#define KAFA_UP_DOWN_MAX 20
#define KAFA_UP_DOWN_MIN -30

#define KAFA_RIGHT_LEFT_MAX 45
#define KAFA_RIGHT_LEFT_MIN -45

#define GOZ_UP_DOWN_MAX 10
#define GOZ_UP_DOWN_MIN -30

#define GOZ_RIGHT_LEFT_MAX 40
#define GOZ_RIGHT_LEFT_MIN -40

using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::dev;

class p {
	public:
		double x;
		double y;
		double z;
		p(double i, double j, double k):x(i), y(j), z(k) {}
		p() { x = y = z = 0; }
		double up_down_angle() {
			return asin(z/(std::sqrt(x*x+y*y+z*z))) * 180.0 / PI;
		}
		double right_left_angle() {
			return asin(y/(std::sqrt(x*x+y*y))) * 180.0 / PI;
		}
};

p dest;

void get_dest() {
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256];
	portno = 12346;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		std::cout << "socket opening error" << std::endl;
		return;
	}

	server = gethostbyname("144.122.225.158");
	if(server == NULL) {
		std::cout << "no such host" << std::endl;
		return;
	}

	memset((char*) &serv_addr, 0, sizeof(serv_addr));

	//bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
	//bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,	server->h_length);

	serv_addr.sin_port = htons(portno);

	if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
		std::cout << "!!!!! error connecting" << std::endl;
		return;
	}

	memset(buffer, 0, 256);

	//bzero(buffer, 256);

	read(sockfd, buffer, 255);

	close(sockfd);

	std::string str(buffer);

	std::stringstream ss(str);

	ss >> dest.x >> dest.y >> dest.z;

	//std::cout << "Coords: ";
	//std::cin >> dest.x >> dest.y >> dest.z;
}

void set_motors(double ud, double rl, Vector& motors) {
	for(int i=0; i<motors.size(); i++) {
		motors[i] = 0.0;
	}

	if(ud != ud || rl != rl) return;

	/*if(ud > 0) { // once kafa sonra göz
		if(ud>KAFA_UP_DOWN_MAX) {
			motors[0] = KAFA_UP_DOWN_MAX;
			ud-=KAFA_UP_DOWN_MAX;
			if(ud>GOZ_UP_DOWN_MAX) {
				motors[3] = GOZ_UP_DOWN_MAX;
			} else {
				motors[3] = ud;
			}
		} else {
			motors[0] = ud;
		}
	} else {
		if(ud<KAFA_UP_DOWN_MIN) {
			motors[0] = KAFA_UP_DOWN_MIN;
			ud-=KAFA_UP_DOWN_MIN;
			if(ud<GOZ_UP_DOWN_MIN) {
				motors[3] = GOZ_UP_DOWN_MIN;
			} else {
				motors[3] = ud;
			}
		} else {
			motors[0] = ud;
		}
	}


	if(rl > 0) {
		if(rl>KAFA_RIGHT_LEFT_MAX) {
			motors[2] = KAFA_RIGHT_LEFT_MAX;
			rl-=KAFA_RIGHT_LEFT_MAX;
			if(rl>GOZ_RIGHT_LEFT_MAX) {
				motors[4] = -GOZ_RIGHT_LEFT_MAX;
			} else {
				motors[4] = -rl;
			}
		} else {
			motors[2] = rl;
		}
	} else {
		if(rl<KAFA_RIGHT_LEFT_MIN) {
			motors[2] = KAFA_RIGHT_LEFT_MIN;
			rl-=KAFA_RIGHT_LEFT_MIN;
			if(rl<GOZ_RIGHT_LEFT_MIN) {
				motors[4] = -GOZ_RIGHT_LEFT_MIN;
			} else {
				motors[4] = -rl;
			}
		} else {
			motors[2] = rl;
		}
	}*/


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

}

int main() {
	Network yarp;

	Property options;
	options.put("device", "remote_controlboard");
	options.put("local", "/head_motor/client");
	options.put("remote", "/icubSim/head");
	PolyDriver robotHead(options);

	if (!robotHead.isValid()) {
		std::cout << "Cannot connect to robot head" << std::endl;
		return 1;
	}

	IPositionControl *pos;
	IVelocityControl *vel;
	IEncoders *enc;
	robotHead.view(pos);
	robotHead.view(vel);
	robotHead.view(enc);
	if (pos==NULL || vel==NULL || enc==NULL) {
		std::cout << "Cannot get interface to robot head" << std::endl;
		robotHead.close();
	}

	int jnts = 0;
	pos->getAxes(&jnts);
	Vector motors;
	motors.resize(jnts);

	Vector tmp;
	tmp.resize(jnts);
	for(int i=0; i<jnts; i++) {
		tmp[i] = 20.0;
	}

	pos->setRefAccelerations(tmp.data());

	for(int i=0; i<jnts; i++) {
		tmp[i] = 10.0;
	}

	pos->setRefSpeeds(tmp.data());

	while(true) {
		get_dest();
		std::cout << "jnts: " << jnts << " up_down"<< dest.up_down_angle() << " right_left" << dest.right_left_angle() << std::endl;
		set_motors(dest.up_down_angle(), dest.right_left_angle(), motors);
		std::cout << "HeadUpDown: " << motors[0] << ", HeadRightLeft: " << motors[2] << ", EyeUpDown: " << motors[3] << ", EyeRightLeft: " << motors[4] << std::endl;
		std::cout << "Send? (Y/n)";
		char c = 'Y';
		std::cin >> c;
		if(c != 'Y') continue;
		bool ok = pos->positionMove(motors.data());
		if(ok) {
			std::cout << "command sent" << std::endl;
		} else {
			std::cout << "command sent failed" << std::endl;
		}
	}

}
