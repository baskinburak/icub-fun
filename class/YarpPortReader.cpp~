#include "YarpPortReader.h"

YarpPortReader::YarpPortReader(std::string name) {
	(this->port).open(name.c_str());
}

std::vector<double> YarpPortReader::getData() {
	yarp::os::Bottle* bottle = (this->port).read(false);
	if(bottle == NULL) return this->prev_data;
	std::vector<double> ret;
	ret.resize(bottle->size());
	for(int i=0; i < bottle->size(); i++) {
		ret[i] = (double)((bottle->get(i)).asDouble());
	}
	this->prev_data = ret;
	return ret;
}
