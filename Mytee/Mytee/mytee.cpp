#include <iostream>
#include <fstream>
#include <time.h>
#include <string>
int main(int length,char**args) {
	time_t now;
	time(&now);
	tm *timeInfo = &tm();
	localtime_s(timeInfo,&now);
	char prefix[64];
	strftime(prefix,64,"%d.%m.%Y %R:%S",timeInfo);
	std::string filename(prefix);
	filename.append(" log.txt");
	std::ofstream log(filename);
	char in;
	while (std::cin>>in) {
		log << in;
		std::cout << in;
	}
	return 0;
}