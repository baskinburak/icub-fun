#include <string>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <vector>

class MotorController {
	private:
		yarp::dev::PolyDriver *driver;
		yarp::dev::IPositionControl *pos;
		yarp::dev::IVelocityControl *vel;
		yarp::dev::IEncoders *enc;
		yarp::os::Property options;
		int jnts;
	public:
		MotorController(std::string robot_name, std::string robot_part, int ref_acc, int ref_speed);
		void sendCommand(std::vector<double> command);
};
