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
vector<ObjPosClient> client_vec(24);
stirng ip = "localhost";
int one_two = 1;
vector<bool> active(24);
vector< vector<double> > all_leds(24);
for(int i= 0;i<24;i++) {
	vector<double> temp(3);
	for(int j = 0;j<3;j++){
		temp[j] = 0.0;
	}
	all_leds[i] = temp;
	active[i] = false;
	if(one_two == 1) {
		ObjPosClient led(ip,14000+(one_two*100)+i);
		client_vec[i] = led;
	}
	else {
		ObjPosClient led(ip,14000+(one_two*100)+i-8);
	}
	if(i == 8) {
		one_two = 2;
	}	
}
/*
ObjPosClient led1_2("localhost",14102);
ObjPosClient led1_3("localhost",14103);
ObjPosClient led1_4("localhost",14104);
ObjPosClient led1_5("localhost",14105);
ObjPosClient led1_6("localhost",14106);
ObjPosClient led1_7("localhost",14107);
ObjPosClient led1_8("localhost",14108);
ObjPosClient led2_1("localhost",14201);
ObjPosClient led2_2("localhost",14202);
ObjPosClient led2_3("localhost",14203);
ObjPosClient led2_4("localhost",14204);
ObjPosClient led2_5("localhost",14205);
ObjPosClient led2_6("localhost",14206);
ObjPosClient led2_7("localhost",14207);
ObjPosClient led2_8("localhost",14208);
ObjPosClient led2_9("localhost",14209);
ObjPosClient led2_10("localhost",14210);
ObjPosClient led2_11("localhost",14211);
ObjPosClient led2_12("localhost",14212);
ObjPosClient led2_14("localhost",14214);
ObjPosClient led2_15("localhost",14215);

*/
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
		            active[(tcm-1)*8+i-1] = true;
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
					cout<<"x: "<<x<<" y: "<<y <<" z: "<<z<<endl;
					
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
