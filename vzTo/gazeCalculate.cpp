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
#include <vector>
#include <math.h>
#define diff 0.00001 
using namespace std;

bool isEqual(double a,double b){
	if(fabs(a-b)>diff)
		return false;
	return true;
}

bool calibreCheck(vector< vector<string>  > &calibre){
	string tcm;
	string led;
	string x;
	string y;
	string z;
	string line;
	int count = 3;
	ifstream myfile ("saved.txt");

	if(myfile.is_open()){
		while(myfile>>tcm){
			vector<string> helper;
			myfile>>led>>x>>y>>z;
			helper.push_back(tcm);
			helper.push_back(led);
			helper.push_back(x);
			helper.push_back(y);
			helper.push_back(z);
			calibre.push_back(helper);
			//cout<<tcm<<" "<<led<<" "<<" "<<x<<" "<<y<<" "<<z<<endl;
			
			count--;
		}
	}
	myfile.close();
	if (count>0)
		return false;
	return true;
}


bool canContinue(vector< vector<double> > vdouble){
	int count = 0;
	for(int i = 0;i<vdouble.size();i++){
		bool flag =false;
		for(int j = 0;j<3;j++){
			if(!isEqual(vdouble[i][j],0.0))
				flag = flag || true;
		}
		if(flag)
			count++;
	}
	if(count<3)
		return false;
	return true;
}
int main(int argc, char *argv[]) {
	vector< vector<string> > calibre;
	if(!calibreCheck(calibre)){
		cout<<"at least 3 led is needed"<<endl;
		return 1;
	}
	vector< vector<double> > vdouble;
	for(int i = 0;i<calibre.size();i++){
		vector<double> tempv(3);
		tempv[0] = atof(calibre[i][2].c_str());
		tempv[1] = atof(calibre[i][3].c_str());
		tempv[2] = atof(calibre[i][4].c_str());
		cout<<i<<endl;
		vdouble.push_back(tempv);
	}
	if(!canContinue(vdouble)){
		cout<<"not enough nonzero values"<<endl;
		return 1;
	}
	vector< vector<double> > active;
	active = vdouble;
	
	yarp::os::Network yarp;
	yarp::os::BufferedPort<yarp::os::Bottle>  outPort;

	bool ok = outPort.open("/turner2");
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
					active[jumper-1][0] = x ;
					active[jumper-1][1] = y ;
					active[jumper-1][2] = z ;
					cout<<"x: "<<active[jumper-1][0]<<" y: "<<active[jumper-1][1] <<" z: "<<active[jumper-1][2]<<endl;
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
