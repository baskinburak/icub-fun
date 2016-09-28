#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <string>
#include <sys/time.h>

yarp::os::Mutex print_mtx;

class Logger : public yarp::os::Thread {
	private:
		yarp::os::BufferedPort<yarp::os::Bottle> port;
		std::string robot_name;
		std::string robot_part;
	public:
		Logger(std::string rn, std::string rp): robot_name(rn), robot_part(rp) {
		}
		void run() {
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
				timeval tv;
				gettimeofday(&tv, 0);
				print_mtx.lock();
				std::cout << tv.tv_sec << "." << tv.tv_usec << "," << robot_part << ",encoders,";
				enc->getEncoders(tmp.data());
				for(int i=0; i<tmp.size()-1; i++) {
					std::cout << tmp[i] << ",";
				}
				std::cout << tmp[tmp.size()-1] << std::endl;
				print_mtx.unlock();


				gettimeofday(&tv, 0);
				print_mtx.lock();
				std::cout << tv.tv_sec << "." << tv.tv_usec  << "," << robot_part << ",torques,";
				itrq->getTorques(tmp.data());
				for(int i=0; i<tmp.size()-1; i++) {
					std::cout << tmp[i] << ",";
				}
				std::cout << tmp[tmp.size()-1] << std::endl;
				print_mtx.unlock();
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


} ;

int main() {
	yarp::os::Network yarp;
	Logger right_arm_logger("icubSim", "right_arm");
	Logger head_logger("icubSim", "head");
	right_arm_logger.start();
	head_logger.start();
	right_arm_logger.join();
	head_logger.join();
	return 0;
}
