#include <yarp/os/all.h>
#include "../class/ObjPosClient.h"
#include "../class/NewObjPosClient.h"
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
#include <vector>
#include <math.h>
#define diff 0.00001 
#define change 0.1
using namespace std;
vector< NewObjPosClient > client_vec;
string ip = "localhost";
int one_two = 1;
int port = 15000;
vector<bool> active(24);
vector< vector<double> > all_leds(24);
void filler(){
	
	for(int i= 0;i<24;i++) {
		vector<double> temp(3);
		for(int j = 0;j<3;j++){
			temp[j] = 0.0;
		}
		all_leds[i] = temp;
		active[i] = false;
		if(one_two == 1) {
			client_vec[i].setHost(ip);
			client_vec[i].setPort(port+(one_two*100)+i);
		}
		else {
			client_vec[i].setHost(ip);
			client_vec[i].setPort(port+(one_two*100)+i-8);
						
		}
		if(i == 8) {
			one_two = 2;
		}	
	}
}

bool isEqual(double a,double b){
	if(fabs(a-b)>diff)
		return false;
	return true;
}
bool isChanged(double a,double b){
	if(fabs(a-b)>change)
		return true;
	return false;
}
bool isZero(vector<double> holder){
	if(isEqual(holder[0],0.0) && isEqual(holder[1],0.0) && isEqual(holder[2],0.0))
		return true;
	return false;
}

int main(int argc, char *argv[]) {
client_vec.resize(24);
	filler();
	yarp::os::Network yarp;
	yarp::os::BufferedPort<yarp::os::Bottle>  outPort;

	bool ok = outPort.open("/PortOutObjData");
	if (!ok) {
		fprintf(stderr, "Failed to create ports.\n");
		fprintf(stderr, "Maybe you need to start a nameserver (run 'yarpserver')\n");
		return 1;
	}
	yarp.connect("/vzPout",outPort.getName());
	while (true) {

        yarp::os::Bottle *input =outPort.read();
        if (input!=NULL) {
            yarp::os::Bottle& output = outPort.prepare();
            output.clear();
            double current;
            string c2;
            int tcm;
            int ledid;
            double x,y,z;
	        int helper = 0;
	        int jumper = 0;
            for(int j = 1;j<input->size();j++){
            	if(helper == 0)
            	{
            		c2 = input->get((jumper*5)+1).asString();
		            tcm = atoi(c2.substr(7,1).c_str());
		            ledid = atoi(c2.substr(8,2).c_str());
		            cout<<"tcm "<<tcm<<" ledid "<<ledid<<" ";
		            active[(tcm-1)*8+ledid] = true;
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
		        		x = x-0.0104737;
						y = y-1.04349; 
						z = z-5.82724;
					}
					
					cout<<"x: "<<x<<" y: "<<y <<" z: "<<z<<"   "<<(tcm-1)*8+ledid<<"   "<< client_vec[(tcm-1)*8+ledid].getPort() <<endl;
					client_vec[(tcm-1)*8+ledid].sendData(x,y,z);
					output.clear();
            	}
		        else{
		        	current = input->get((jumper*5)+helper+1).asDouble();
		           	output.addDouble(current);
		           	helper++;
		        }
		        outPort.write();

           }
           cout<<endl<<endl<<endl<<endl<<endl;
        }
    }
  
  return 0;
}
