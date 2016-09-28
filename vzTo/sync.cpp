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

int main(int argc, char *argv[]) {
	ofstream myfile("saved.txt");

  // Set up YARP
	yarp::os::Network yarp;
	// Make two ports called /hello/in and /hello/out
	// We'll send "Bottles" (a simple nested list container) between these ports
	yarp::os::BufferedPort<yarp::os::Bottle>  outPort;

	bool ok = outPort.open("/turner");
	if (!ok) {
		fprintf(stderr, "Failed to create ports.\n");
		fprintf(stderr, "Maybe you need to start a nameserver (run 'yarpserver')\n");
		return 1;
	}
	// Make a connection between the output port and the input port
	yarp.connect("/vzPout",outPort.getName());
	bool onetime = 1;
	while (true && onetime) {
        yarp::os::Bottle *input =outPort.read();
        if (input!=NULL) {
            onetime = 0;
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
		          	myfile<<tcm<<" "<<ledid<<" ";
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

					myfile<<" "<<x<<" "<<y <<" "<<z<<"\n";
					output.clear();
            	}
		        else{
		        	current = input->get((jumper*5)+helper+1).asDouble();
		           	output.addDouble(current);
		           	helper++;
		        }
		        
		       

		        outPort.write();

           }
        }

    }
    myfile.close();

    
  
  return 0;
}
