#include "ObjPosClient.h"
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <sstream>

ObjPosClient::ObjPosClient(std::string h, int p) {
	this->host = host;
	this->portno = p;
}

ObjPosClient::ObjPosClient(const char* h, int p) {
	this->host = std::string(h);
	this->portno = p;
}

void ObjPosClient::sendData(double x, double y, double z) {
	int sockfd, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) {
		std::cout << "\033[0;31m[ObjPosClient] error opening socket\033[0m" << std::endl;
		return;
	}

	server = gethostbyname((this->host).c_str());

	if (server == NULL) {
		std::cout << "\033[0;31m[ObjPosClient] no such host\033[0m" << std::endl;
		close(sockfd);
		return;
	}

	memset((char*)&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;

	memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
	serv_addr.sin_port = htons(portno);

	if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
		std::cout << "\033[0;31m[ObjPosClient] error connecting" << this->host << " " << this->portno << "\033[0m" << std::endl;
		close(sockfd);
		return;
	}
	
	std::stringstream ss;
	ss << x << " " << y << " " << z;

	std::string str = ss.str();

	n = write(sockfd,str.c_str(),strlen(str.c_str()));
	
	if(n<0) {
		close(sockfd);
		throw std::string("error writing");
	}
	
	close(sockfd);
}
