#include "face_controller.h"

faceController::faceController() {
	this->last_opt = "no";
	this->current_opt = "no";
	this->no = "no";

    this->client_name = "/icub_kovan/face_expr";
    this->server_name = "/icub/face/emotions/in";
    
}

void faceController::setFace(const char * opt,const char * emo){
	if(this->last_opt.compare(this->no)){
		this->last_opt = opt;
		this->last_emo = opt;
	}
	else {
		this->last_opt = this->current_opt;
		this->last_emo = this->current_emo;
	}
	yarp::os::Network yarp;
	yarp::os::RpcClient port;
    port.open(this->client_name);
    while (true) {
		if (port.getOutputCount()==0) {
			printf("Trying to connect to %s\n", this->server_name);
			yarp.connect(this->client_name,this->server_name);
		} else {
			yarp::os::Bottle cmd;
			cmd.addString("set");
			cmd.addString(opt);
			cmd.addString(emo);
			printf("Sending message... %s\n", cmd.toString().c_str());
			yarp::os::Bottle response;
			port.write(cmd,response);
			printf("Got response: %s\n", response.toString().c_str());
			port.close();
			yarp.disconnect(this->client_name,this->server_name);
			return;
		}
    }
	
}
std::string faceController::getLastOpt(){
	return this->last_opt;
}
std::string faceController::getCurrentOpt(){
	return this->current_opt;
}
std::string faceController::getLastEmo(){
	return this->last_emo;
}
std::string faceController::getCurrentEmo(){
	return this->current_emo;
}
