#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
int main(int length,char**args) {
	using namespace std;
	time_t now;
	tm timeInfo;
	char prefix[64];
	ofstream log("mytee.log",ofstream::app);
	string in;
	while (getline(cin,in)) {
		time(&now);
		localtime_s(&timeInfo, &now);
		strftime(prefix, 64, "%d.%m.%Y %R:%S",&timeInfo);
		cout << in << endl;
		log << prefix << " " << in << endl;
	}
	return 0;
}