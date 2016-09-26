#include "class/ObjPosServer.h"
#include <vector>

using namespace std;

int main() {
	ObjPosServer obj_server(12344);
	obj_server.start();

	while(true) {
		vector<double> a = obj_server.getObjCoordinates();
		cout << a[0] << " " << a[1] << " " << a[2] << endl;
	}
}
