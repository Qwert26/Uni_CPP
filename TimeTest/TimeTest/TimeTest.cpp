#include "StopWatch.h"
#include "stack.hpp"
#include <stdlib.h>
#include <iostream>
#define MEASURETIME(description,repetitions,instructions2test)	StopWatch sw;\
																sw.start();\
																for(int i=0;i<repetitions;i++) {instructions2test}\
																double end=sw.stop();\
																std::cout<<"My computer requires "<<end<<" seconds to execute "<<description<<" "<<repetitions<<" times.\n";
void baseOperation(void);
int main(void) {
	//100000 Wiederholung bräuchten ungefähr 20 Minuten!
	MEASURETIME("Baseoperation",10000,baseOperation();)
	return 0;
}
void baseOperation(void) {
	Stack s(100000);
	for (int c=0;c<100000;c++) {
		s.push(rand());
	}
}