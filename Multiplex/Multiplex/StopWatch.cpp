#include "StopWatch.h"
#include <iostream>
StopWatch::StopWatch() {}
StopWatch::~StopWatch() {}
void StopWatch::start(void) {
	if (started) {
		std::cout<<"StopWatch already started!"<<std::endl;
	} else {
		started = true;
		zeitpunkt = clock();
	}
}
double StopWatch::stop(void) {
	if (started) {
		zeitpunkt = clock() - zeitpunkt;
		return (double)zeitpunkt / (double)CLOCKS_PER_SEC;
	} else {
		std::cout<<"StopWatch not started!"<<std::endl;
		return 0;
	}
}