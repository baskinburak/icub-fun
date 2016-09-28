#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/dev/all.h>
#include <vector>
#include <string>

class YarpPortReader {
	private:
		std::vector<double> prev_data;
		yarp::os::BufferedPort<yarp::os::Bottle> port;
	public:
		YarpPortReader(std::string portname);
		std::vector<double> getData();
};
