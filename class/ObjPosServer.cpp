#include "ObjPosServer.h"
#include <sstream>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void ObjPosServer::startServer(int portno) {
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
		std::cout << "ERROR on binding" << std::endl;
		return;
	}

	listen(this->sockfd, 5);
}

void ObjPosServer::run() {
	this->startServer(this->portno);

	struct sockaddr_in cli_addr;
	char buffer[256];
	while(true) {
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
		std::stringstream ss;
		ss << std::string(buffer);
		(this->coorMutex).lock();
		ss >> (this->obj_x) >> (this->obj_y) >> (this->obj_z);
		(this->coorMutex).unlock();
	}
	close(this->sockfd);
}

void ObjPosServer::onStop() {
	std::cout << "ObjPosServer has stopped." << std::endl;
}

void ObjPosServer::beforeStart() {
	std::cout << "ObjPosServer is about to start." << std::endl;
}

void ObjPosServer::afterStart(bool succ) {
	if(succ) {
		std::cout << "ObjPosServer started successfully." << std::endl;
	} else {
		std::cout << "ObjPosServer cannot be started." << std::endl;
	}
}

bool ObjPosServer::threadInit() {
	std::cout << "ObjPosServer initialization..." << std::endl;
	this->obj_x = 0.0;
	this->obj_y = 0.0;
	this->obj_z = 0.0;
	return true;
}

void ObjPosServer::threadRelease() {
	std::cout << "ObjPosServer release..." << std::endl;
}

std::vector<double> ObjPosServer::getObjCoordinates() {
	std::vector<double> res;
	(this->coorMutex).lock();
	res.push_back(this->obj_x);
	res.push_back(this->obj_y);
	res.push_back(this->obj_z);
	(this->coorMutex).unlock();
	return res;
}
