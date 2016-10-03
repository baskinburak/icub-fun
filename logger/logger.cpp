#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <string>
#include <sys/time.h>
#include<pthread.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <cstdio>
#include "../class/YarpPortReader.h"
#include <fstream>

#define LOG_SECONDS 0.01

//yarp::os::Mutex print_mtx;
pthread_mutex_t print_mtx;
std::string folder;

class YarpPortLogger : public yarp::os::Thread {
	private:
		YarpPortReader reader;
		std::string start_str;
		std::string filename;
		std::string header;
	public:
		YarpPortLogger(std::string portname, std::string str, std::string f, std::string h) : reader(portname), start_str(str), filename(f), header(h) {}
		void run() {
			std::ofstream fp((folder + std::string("/") + filename).c_str(), std::ofstream::out);
			fp << header << std::endl;
			while(true) {
				usleep(1000*1000*LOG_SECONDS);
				std::vector<double> dat = reader.getData();
				if(dat.size()==0)continue;
				timeval tv;
				gettimeofday(&tv, 0);
				pthread_mutex_lock(&print_mtx);
				fp << tv.tv_sec*1000000+tv.tv_usec << "," << start_str << ",";
				for(int i=0; i<dat.size()-1; i++) {
					fp << dat[i] << ",";
				}
				fp << dat[dat.size()-1] << std::endl;
				pthread_mutex_unlock(&print_mtx);
			}
		}
};

class Logger : public yarp::os::Thread {
	private:
		yarp::os::BufferedPort<yarp::os::Bottle> port;
		std::string robot_name;
		std::string robot_part;
		std::string filename;
		std::string header;
	public:
		Logger(std::string rn, std::string rp, std::string f, std::string h): robot_name(rn), robot_part(rp), filename(f), header(h) {
		}
		void run() {
			std::ofstream fp((folder + std::string("/") + filename).c_str(), std::ofstream::out);
			fp << header << std::endl;
			if(this->robot_name != "icub" && this->robot_name != "icubSim") {
				std::cout << "[ERR] robot_name must be icub or icubSim" << std::endl;
				return;
			}

			if(robot_part != "head" && robot_part != "right_arm" && robot_part != "left_arm" && robot_part != "left_leg" && robot_part != "right_leg" && robot_part != "torso") {
				std::cout << "[ERR] robot_part must be head, right_arm, left_arm, left_leg, right_leg or torso" << std::endl;
			}

			yarp::os::Property options;

			options.put("device", "remote_controlboard");
			options.put("robot", robot_name.c_str());
			std::string remote = std::string("/") + robot_name + std::string("/") + robot_part;
			std::string local = (std::string("/icub_kovan/client/logger") + remote);
			options.put("local", local.c_str());
			options.put("remote", remote.c_str());

			yarp::dev::PolyDriver driver(options);

			if(!(driver.isValid())) {
				std::cout <<  "[ERR] cannot connect to driver" << std::endl;
				return;
			}

			yarp::dev::IPositionControl *pos;
			yarp::dev::IVelocityControl *vel;
			yarp::dev::IEncoders *enc;
			yarp::dev::ITorqueControl *itrq;

			driver.view(pos);
			driver.view(vel);
			driver.view(enc);
			driver.view(itrq);

			if(pos == NULL || vel == NULL || enc == NULL || itrq == NULL) {
				std::cout << "[ERR] Interface error" << std::endl;
				return;
			}


			int jnts;
			pos->getAxes(&jnts);

			yarp::sig::Vector tmp;
			tmp.resize(jnts);

			while(true) {
				usleep(1000*1000*LOG_SECONDS);
				timeval tv;
				gettimeofday(&tv, 0);
				pthread_mutex_lock(&print_mtx);
				fp << tv.tv_sec*1000000+tv.tv_usec << "," << robot_part << "_encoders,";
				enc->getEncoders(tmp.data());
				for(int i=0; i<tmp.size()-1; i++) {
					fp << tmp[i] << ",";
				}
				fp << tmp[tmp.size()-1] << std::endl;
				pthread_mutex_unlock(&print_mtx);


				/*gettimeofday(&tv, 0);
				pthread_mutex_lock(&print_mtx);
				std::cout << tv.tv_sec << "." << tv.tv_usec  << "," << robot_part << ",torques,";
				itrq->getTorques(tmp.data());
				for(int i=0; i<tmp.size()-1; i++) {
					std::cout << tmp[i] << ",";
				}
				std::cout << tmp[tmp.size()-1] << std::endl;
				pthread_mutex_unlock(&print_mtx);*/
			}

		}

		void onStop() {
		
		}

		void beforeStart() {
		
		}

		void afterStart(bool succ) {

		}

		bool threadInit() {
		
		}

		void threadRelease() {
		
		}


};

class NetworkLogger : public yarp::os::Thread {
	private:
		std::string start_str;
		int type;
		int portno;
		int sockfd;
		std::string filename;
		std::string header;
	public:
		NetworkLogger(int p, int t, std::string s, std::string f, std::string h): portno(p), type(t), start_str(s), filename(f), header(h) {
		}
		void run() {
			std::ofstream fp((folder + std::string("/") + filename).c_str(), std::ofstream::out);
			fp << header << std::endl;
			socklen_t clilen;
			struct sockaddr_in serv_addr;
			this->sockfd = socket(AF_INET, SOCK_STREAM, 0);
			if (this->sockfd < 0) {
				std::cout << "ERROR opening socket" << std::endl;
				return;
			}

			memset((char*)&serv_addr, 0, sizeof(serv_addr));

			serv_addr.sin_family = AF_INET;
			serv_addr.sin_addr.s_addr = INADDR_ANY;
			serv_addr.sin_port = htons(portno);

			if (bind(this->sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)  {
				std::cout << "ERROR on binding " <<this->portno << std::endl;
				return;
			}

			listen(this->sockfd, 5);

			struct sockaddr_in cli_addr;
			char buffer[256];
			while(true) {
				usleep(1000*1000*LOG_SECONDS);
				socklen_t clilen = sizeof(cli_addr);
				int newsockfd = accept(this->sockfd, (struct sockaddr*) &cli_addr, &clilen);
				if(newsockfd < 0) {
					std::cout << "ERROR on accept" << std::endl;
					close(newsockfd);
					break;
				}
				memset(buffer, 0, 256);
				int n = read(newsockfd, buffer, 255);
				if(n < 0) {
					std::cout << "ERROR on read" << std::endl;
					close(newsockfd);
					break;
				}
				close(newsockfd);
				timeval tv;
				gettimeofday(&tv, 0);
				pthread_mutex_lock(&print_mtx);
				fp << tv.tv_sec*1000000+tv.tv_usec << "," <<this->start_str <<",";
				if(type == 0) {
					double a,b,c;
					std::sscanf(buffer, "%lf %lf %lf", &a, &b, &c);
					fp << a << "," << b << "," << c;
				} else if(type==1) {
					
					fp << buffer;
				}
				fp << std::endl;
				pthread_mutex_unlock(&print_mtx);
			}
			close(this->sockfd);

		}

		void onStop() {
		
		}

		void beforeStart() {
		
		}

		void afterStart(bool succ) {

		}

		bool threadInit() {
		
		}

		void threadRelease() {
		
		}
};

int main(int argc, char* argv[]) {
	if(argc!=2) {
		std::cout << "need 1 folder argument" << std::endl;
		return 0;
	}
	pthread_mutex_init(&print_mtx, NULL);
	
	folder = std::string("icub_interaction8");
	yarp::os::Network yarp;
	Logger right_arm_logger("icub", "right_arm", "right_arm_encoders", "time,right_arm_encoders,jnt0,jnt1,jnt2,jnt3,jnt4,jnt5,jnt6,jnt7,jnt8,jnt9,jnt10,jnt11,jnt12,jnt13,jnt14,jnt15");
	//Logger head_logger("icub", "head");
	
	NetworkLogger obj_pos(13000,0,"object_position","object_position","time,object_position,x,y,z");
	//NetworkLogger head_pos(13001,0,"human_head_pos");
	//NetworkLogger head_or_object(13002,1,"head_or_obj");

	YarpPortLogger right_arm_ft("/icub/right_arm/analog/logger","right_arm_force_torque", "right_arm_force_torque", "time,right_arm_force_torque,force_x, force_y, force_z, torque_x, torque_y, torque_z");
	YarpPortLogger right_hand_fingers("/icub/right_hand/analog/logger", "right_hand_finger_encoders", "right_hand_finger_encoders", "time,right_hand_finger_encoders,jnt0,jnt1,jnt2,jnt3,jnt4,jnt5,jnt6,jnt7,jnt8,jnt9,jnt10,jnt11,jnt12,jnt13,jnt14,jnt15");

	obj_pos.start();
	//head_pos.start();
	//head_or_object.start();
	right_arm_logger.start();
	//head_logger.start();
	right_arm_ft.start();
	right_hand_fingers.start();

	while(true);
	
	pthread_mutex_destroy(&print_mtx);
	return 0;
}
