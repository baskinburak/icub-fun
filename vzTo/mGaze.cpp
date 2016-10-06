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
#define _USE_MATH_DEFINES
using namespace std;
vector< NewObjPosClient > client_vec;
string ip = "10.0.0.1";
string ip2= "localhost";
int one_two = 1;
int port = 17000;
NewObjPosClient obj1;
NewObjPosClient obj2;
NewObjPosClient obj3;
NewObjPosClient handChose;
NewObjPosClient headChose;
NewObjPosClient gaze1;
NewObjPosClient gaze2;
vector< vector<double> > onTable(3);
vector< vector<double> > hatLeds(3);
vector< vector<double> > gazePoints(3);
vector<double> average(3);
vector<bool> broken(3);
vector<double > icub;
vector<double> head(3);
vector<double> hand(3);
vector<double> degrees(4);
vector< vector<double> > handToObj;
vector< vector<double> > vHold; //created vHold; // 00 is hat1 // 01 icub // 02 led1 // 03 led2 // 04 led 3 // 05 gaze1 // 06 geze2 //07 gaze3
void filler(){
	gaze1.setHost(ip2);
	gaze2.setHost(ip2);
	obj1.setHost(ip2);
	obj2.setHost(ip2);
	obj3.setHost(ip2);
	handChose.setHost(ip);
	headChose.setHost(ip);
	obj1.setPort(15001);
	obj2.setPort(15002);
	obj3.setPort(15003);
	handChose.setPort(15005);
	headChose.setPort(15006);
	gaze1.setPort(15007);
	gaze2.setPort(15008);
	for(int i=0;i<7;i++){
		vector<double> temp(3);
		for(int j = 0;j<3;j++){
			temp[j] = 0.0;
		}
		vHold.push_back(temp);
	}
	for(int i=0;i<3;i++){
		vector<double> temp(3);
		for(int j = 0;j<3;j++){
			temp[j] = 0.0;
		}
		hand[i] = 0.0;
		head[i] = 0.0;
		handToObj.push_back(temp);
		onTable[i] = temp;
		hatLeds[i] = temp;
		gazePoints[i] = temp;
	}
	for(int i= 0;i<24;i++) {
		vector<double> temp(3);
		for(int j = 0;j<3;j++){
			temp[j] = 0.0;
		}
		if(one_two == 1) {
			client_vec[i].setHost(ip2);
			client_vec[i].setPort(port+(one_two*100)+i);
		}
		else {
			client_vec[i].setHost(ip2);
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

void calcAverage(int divider,bool isO,bool isS){
	/*if(isO && isS) {
		average[0] = (hatLeds[1][0] + hatLeds[2][0])/divider;
		average[1] = (hatLeds[1][1] + hatLeds[2][1])/divider;
		average[2] = (hatLeds[1][2] + hatLeds[2][2])/divider;
	}
	else {
		if(isO) {*/
			average[0] = hatLeds[1][0];
			average[1] = hatLeds[1][1];
			average[2] = hatLeds[1][2];
	/*	}
		else {
			average[0] = hatLeds[2][0];
			average[1] = hatLeds[2][1];
			average[2] = hatLeds[2][2];			
		}
	}*/
}
void handVec(){
	for(int i=0;i<3;i++){
		for(int j= 0;j<3;j++){
			handToObj[i][j] = onTable[i][j] - hand[j];
		}
	}
}



void handlevHold(){
	vHold[0][0] = hatLeds[0][0] -average[0];
	vHold[0][1] = hatLeds[0][1] -average[1];
	vHold[0][2] = hatLeds[0][2] -average[2];
	vHold[1][0] = icub[0]-average[0]; 
	vHold[1][1] = icub[1]-average[1];
	vHold[1][2] = icub[2]-average[2];
	vHold[2][0] = onTable[0][0]-average[0];
	vHold[2][1] = onTable[0][1]-average[1];
	vHold[2][2] = onTable[0][2]-average[2];
	vHold[3][0] = onTable[1][0]-average[0];
	vHold[3][1] = onTable[1][1]-average[1];
	vHold[3][2] = onTable[1][2]-average[2];
	vHold[4][0] = onTable[2][0]-average[0];
	vHold[4][1] = onTable[2][1]-average[1];
	vHold[4][2] = onTable[2][2]-average[2];
	vHold[5][0] = gazePoints[0][0]-average[0];
	vHold[5][1] = gazePoints[0][1]-average[1];
	vHold[5][2] = gazePoints[0][2]-average[2];
	vHold[6][0] = gazePoints[1][0]-average[0];
	vHold[6][1] = gazePoints[1][1]-average[1];
	vHold[6][2] = gazePoints[1][2]-average[2];

	
}

void updatevHold(){
	int divider = 1;
	bool isOneActive = true;
	bool isSecondActive = true;
	if(broken[0]){
		cout<<"need to see 1.6"<<endl;
		return;
	}
	if(broken[1]){
		cout<<"1.7 is not active"<<endl;
		divider--;
		isOneActive = false;
	}
	/*if(broken[2]){
//		cout<<"1.2 is not active"<<endl;
		divider--;
		isSecondActive = false;
	}*/
	if(divider == 0){
//		cout<<"need to see at least one of 2.10 or 2.14"<<endl;
		return;
	}
	calcAverage(divider,isOneActive,isSecondActive);

		
}


double vecLength(vector<double> &v1){
	return sqrt((v1[0]*v1[0])+(v1[1]*v1[1])+(v1[2]*v1[2]));
}


double dotProduct(vector<double> &v1,vector<double> &v2){
	double xx,yy,zz;
	double l1,l2;
	xx = v1[0]*v2[0];
	yy = v1[1]*v2[1];
	zz = v1[2]*v2[2];
	l1 = sqrt((v1[0]*v1[0])+(v1[1]*v1[1])+(v1[2]*v1[2]));
	l2 = sqrt((v2[0]*v2[0])+(v2[1]*v2[1])+(v2[2]*v2[2]));
	return acos((xx+yy+zz)/(l1*l2));
}
int chosen(){
	float min = M_PI;
	int current = 0;
	for(int i=1;i<7;i++){
		degrees[i] = dotProduct(vHold[i],vHold[0]);
//		cout<<degrees[i]<<" ";
		if(min>degrees[i]){
			min = degrees[i];
			current = i;
		}
	}
//	cout<<endl;
	return current;
}

int based_on_hand(){
//	cout<<vecLength(handToObj[0])<<" "<<vecLength(handToObj[1])<<" "<<vecLength(handToObj[2])<<endl;
	int current = 0;
	int min =vecLength(handToObj[0]);
	if(min>vecLength(handToObj[1])){
		min = vecLength(handToObj[1]);
		current = 1;
	}
	if(min>vecLength(handToObj[2])){
		min = vecLength(handToObj[2]);
		current = 2;
	}
	if(min>5.0)
		current = -1;
	return current;
}

int main(int argc, char *argv[]) {
	client_vec.resize(24);
	string headER("head");
	string obj1ER("obj1");
	string obj2ER("obj2");
	string obj3ER("obj3");
	string gaze1ER("gaze1");
	string gaze2ER("gaze2");
	filler();
	int oldchosen = 0;
	int newchosen = 0;
	int oldHand = 0;
	int newHand = 0;

	icub.push_back(0.7507973);icub.push_back(-0.059904000);icub.push_back(0.79237);
	onTable[0][0] = 3.8508463;		//leftmost x
	onTable[0][1] = -2.93532;		//leftmost y
	onTable[0][2] = -4.16355;		//leftmost z
	onTable[1][0] = 4.0674063;		//middle x
	onTable[1][1] = 0.130271000;	//middle y
	onTable[1][2] = -3.48792;		//middle z
	onTable[2][0] = 4.1345662999;	//rightmost x
	onTable[2][1] = 2.64757999;		//rightmost y
	onTable[2][2] = -3.66451;		//rightmost z
	gazePoints[0][0] = 4.3098763;	//leftgaze x
	gazePoints[0][1] = -7.83328;	//leftgaze y
	gazePoints[0][2] = 0.961610000;	//leftgaze z
	gazePoints[1][0] = 7.3232462;	//rightgaze x
	gazePoints[1][1] = 9.88191;		//rightgaze y
	gazePoints[1][2] = 2.131280000;	//rightgaze z
	
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
		usleep(1000*1000*0.3);
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
	        bool handled = false;
	        bool alter = false;
	        broken[2] = false; ////////////////////////CHANGE IN CASE OF THREE LED AT HEAD
            for(int j = 1;j<input->size();j++){
            	if(helper == 0)
            	{
            		c2 = input->get((jumper*5)+1).asString();
		            tcm = atoi(c2.substr(7,1).c_str());
		            ledid = atoi(c2.substr(8,2).c_str());
		            helper++;
            	}
            	else if(helper == 4)
            	{

            		helper = 0;
            		jumper++;
            		x = output.get(0).asDouble();
            		y = output.get(1).asDouble();
            		z = output.get(2).asDouble();
            		if(isEqual(x,0.0) && isEqual(y,0.0) && isEqual(z,0.0)){
            			if(ledid == 6)
            				broken[0] =true;
            			else if(ledid == 7)
            				broken[7] = true;
            			else if(ledid == 2)
            				broken[2] =false;
						handled = true;
					}
            		else{
		        		x = x-0.0104737;
						y = y-1.04349; 
						z = z-5.82724;
					}
					if(tcm == 1 && ledid == 6 && handled == false){
		
						if(isChanged(hatLeds[0][0],x) || isChanged(hatLeds[0][1],y) || isChanged(hatLeds[0][2],z)){
							hatLeds[0][0] = x;
							hatLeds[0][1] = y;
							hatLeds[0][2] = z;
							client_vec[(tcm-1)*8+ledid].sendData(x,y,z);
							alter = true;
							broken[0] =false;
						}
					}
					else if(tcm == 1 && ledid == 7 && handled == false){
						if(isChanged(hatLeds[1][0],x) || isChanged(hatLeds[1][1],y) || isChanged(hatLeds[1][2],z)){
							hatLeds[1][0] = x;
							hatLeds[1][1] = y;
							hatLeds[1][2] = z;
							client_vec[(tcm-1)*8+ledid].sendData(x,y,z);
							alter = true;
							broken[1] =false;
						}
					}
					else if(tcm == 1 && ledid == 5 && handled == false){
						if(isChanged(hand[0],x) || isChanged(hand[1],y) || isChanged(hand[2],z)){
							hand[0] = x;
							hand[1] = y;
							hand[2] = z;
							client_vec[(tcm-1)*8+ledid].sendData(x,y,z);
							alter =true;
						}
					}
					else if(tcm == 1 && ledid == 1 && handled == false){
						if(isChanged(head[0],x) || isChanged(head[1],y) || isChanged(head[2],z)){
							head[0] = x;
							head[1] = y;
							head[2] = z;
							client_vec[(tcm-1)*8+ledid].sendData(x,y,z);
							alter = true;
						}
					}
					/*else if(tcm == 1 && ledid == 6 && handled == false){
						if(isChanged(onTable[1][0],x) || isChanged(onTable[1][1],y) || isChanged(onTable[1][2],z)){
							onTable[1][0] = x;
							onTable[1][1] = y;
							onTable[1][2] = z;
							//client_vec[(tcm-1)*8+ledid].sendData(x,y,z);
							alter = true;
						}
					}
					else if(tcm == 1 && ledid == 7 && handled == false){
						if(isChanged(onTable[2][0],x) || isChanged(onTable[2][1],y) || isChanged(onTable[2][2],z)){
							onTable[2][0] = x;
							onTable[2][1] = y;
							onTable[2][2] = z;
							//client_vec[(tcm-1)*8+ledid].sendData(x,y,z);
							alter = true;
						}
					}
					*/
					handled= false;
					
					output.clear();
            	}
		        else{
		        	current = input->get((jumper*5)+helper+1).asDouble();
		           	output.addDouble(current);
		           	helper++;
		        }
		        outPort.write();

           }
           	if(alter){
           		obj1.sendData(onTable[0][0],onTable[0][1],onTable[0][2]);
           		obj2.sendData(onTable[1][0],onTable[1][1],onTable[1][2]);
           		obj3.sendData(onTable[2][0],onTable[2][1],onTable[2][2]);
           		gaze1.sendData(gazePoints[0][0],gazePoints[0][1],gazePoints[0][2]);
           		gaze2.sendData(gazePoints[1][0],gazePoints[1][1],gazePoints[1][2]);
           		updatevHold();
           		handlevHold();
           		handVec();
           		newchosen = chosen();
           		newHand = based_on_hand();
           		if(newHand != oldHand){
           			cout<<"chosen hand "<<newHand<<endl;
           			oldHand = newHand;
           			switch(oldHand){
           				case 0:
           					handChose.sendHorO((char *)"obj1");break;
           				case 1:
           					handChose.sendHorO((char *)"obj2");break;
           				case 2:
           					handChose.sendHorO((char *)"obj3");break;
           				default:
           					handChose.sendHorO((char *)"noObj");break;
           			}
           		}
           		if(oldchosen!=newchosen){
           			cout<<"chosen look "<<newchosen<<endl;
           			oldchosen = newchosen;
					switch(newchosen){
						case 1:
							headChose.sendHorO((char *)"head");break;
						case 2:
							headChose.sendHorO((char *)"obj1");break;
						case 3:
							headChose.sendHorO((char *)"obj2");break;						
						case 4:
							headChose.sendHorO((char *)"obj3");break;
						case 5:
							headChose.sendHorO((char *)"gaze1");break;
						case 6:
							headChose.sendHorO((char *)"gaze2");break;
					} 
           		}
           	}
           
        }
    }
  
  return 0;
}
