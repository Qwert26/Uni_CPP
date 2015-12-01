#include "StopWatch.h"
#include "stack.hpp"
#include <stdlib.h>
#include <iostream>
#define MEASURETIME(description,repetitions,instructions2test)	StopWatch sw;\
																sw.start();\
																for(int i=0;i<repetitions;i++) {instructions2test}\
																std::cout<<"My computer requires "<<sw.stop()<<" seconds to execute "<<description<<" "<<repetitions<<" times.\n";
void baseOperation(void);
void copyAssignmentTest(void);
void moveAssignmentTest(void);
int main(void) {
	//100000 Wiederholung bräuchten ungefähr 21 Minuten!
	{MEASURETIME("Baseoperation", 10000, baseOperation();)}
	//100000 Wiederholungen bräuchten ungefähr 31 Minuten!
	{MEASURETIME("Copy Assignment Test", 10000, copyAssignmentTest();)}
	//100000 Wiederholungen bräuchten ungefähr 21 Minuten!
	{MEASURETIME("Move Assignment Test",10000,moveAssignmentTest();)}
	return 0;
}
void baseOperation(void) {
	Stack s(100000);
	for (int c=0;c<100000;c++) {
		s.push(rand());
	}
}
void copyAssignmentTest(void) {
	Stack s(100000);
	for (int c = 0; c<100000; c++) {
		s.push(rand());
	}
	Stack s2(s);
}
Stack randomStack(void) {
	Stack s(100000);
	for (int c = 0; c<100000; c++) {
		s.push(rand());
	}
	return s;
}
void moveAssignmentTest(void) {
	const Stack&& s = randomStack();
}