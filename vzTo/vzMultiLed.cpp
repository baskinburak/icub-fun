/*
 * Copyright: (C) 2010 RobotCub Consortium
 * Author: Paul Fitzpatrick
 * CopyPolicy: Released under the terms of the LGPLv2.1 or later, see LGPL.TXT
 */
#include <yarp/os/all.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <sstream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

using namespace std;
pthread_mutex_t mutex_coords;
double glo_x, glo_y, glo_z;

/*void* send_data(void* a) {
	int sockfd, newsockfd, n;
	socklen_t clilen;
	int portno=12346;
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		cout << "socket open error";
		exit(0);
	}
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(portno);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		cout << "bind error" << endl;
		exit(0);
	}
	listen(sockfd,5);
	
	clilen = sizeof(cli_addr);
	while(1) {
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		cout << "hop" << endl;
		if (newsockfd < 0) {
		  cout << "accept error" << endl;exit(0) ;
		}
		bzero(buffer,256);
		stringstream ss;
		pthread_mutex_lock(&mutex_coords);
		ss << glo_x << " " << glo_y << " " << glo_z;
		pthread_mutex_unlock(&mutex_coords);
		strcpy(buffer, ss.str().c_str());
		n = write(newsockfd,buffer, 256);
		if (n < 0) cout << "error writing" << endl;

		close(newsockfd);

	}
}*/
/*void get_dest() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    portno = 12344;
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
    //bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr,    server->h_length);

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
*/

int main(int argc, char *argv[]) {
  /* 	pthread_mutex_init(&mutex_coords, NULL);
	pthread_t socket_thread;
	pthread_create(&socket_thread, NULL, send_data, NULL);
*/	
  // Set up YARP
  yarp::os::Network yarp;
  // Make two ports called /hello/in and /hello/out
  // We'll send "Bottles" (a simple nested list container) between these ports
  yarp::os::BufferedPort<yarp::os::Bottle>  outPort;
  
  bool ok = outPort.open("/MultiLedTurner");
  if (!ok) {
    fprintf(stderr, "Failed to create ports.\n");
    fprintf(stderr, "Maybe you need to start a nameserver (run 'yarpserver')\n");
    return 1;
  }
  // Make a connection between the output port and the input port
    yarp.connect("/vzPout",outPort.getName());
  while (true) {

        yarp::os::Bottle *input =outPort.read();
        if (input!=NULL) {
            yarp::os::Bottle& output = outPort.prepare();
            output.clear();
            double current;
            string c2;
            string tcm;
            string ledid;
            double x,y,z;
	        int helper = 0;
	        int jumper = 0;
            for(int j = 1;j<input->size();j++){
            	if(helper == 0)
            	{
            		c2 = input->get((jumper*5)+1).asString();
		            tcm = c2.substr(7,1);
		            ledid = c2.substr(8,2);
		            cout<<"tcm "<<tcm<<" ledid "<<ledid<<" ";
		            helper++;
            	}
            	else if(helper == 4)
            	{

            		helper = 0;
            		jumper++;
            		x = output.get(0).asDouble();
            		y = output.get(1).asDouble();
            		z = output.get(2).asDouble();
            		if(x == 0.0 && y==0.0 && z == 0.0);
            		else{
		        		x = x+3.059691;
						y = y-0.552323; 
						z = z-9.433398;
					}
					/*pthread_mutex_lock (&mutex_coords);
					glo_y = y;
					glo_x = x;
					glo_z = z;
					pthread_mutex_unlock (&mutex_coords);
					*/cout<<"x: "<<x<<" y: "<<y <<" z: "<<z<<endl;
					output.clear();
            	}
		        else{
		        	current = input->get((jumper*5)+helper+1).asDouble();
		           	output.addDouble(current);
		           	helper++;
		        }
		        
		       
				//cout<<"EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE"<<endl;
		        /*for(int k = 0;k<output.size();k++){
		        	cout<<output.get(k).toString()<<" ";
		        }*/
		        outPort.write();

           }
                      		        cout<<endl<<endl<<endl<<endl<<endl;
        }
    }
//	pthread_join(socket_thread, NULL);
    
  
  return 0;
}
