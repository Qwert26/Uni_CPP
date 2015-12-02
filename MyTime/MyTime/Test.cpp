#include "mytime.h"
#include <iostream>
using namespace std;//Keine Lust ständig std:: zu schreiben.
int main(void) {
	MyTime time(0,0,75);
	cout << time << endl;
	time += 59;
	cout << time << endl;
	time += time;
	cout << time << endl;
	cout << (int)time << endl;
	return 0;
}