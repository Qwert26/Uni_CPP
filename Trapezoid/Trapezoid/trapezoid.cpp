#include <cmath>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
using namespace std;
volatile int threadCount = 1;
volatile double sum = 0.0;
double stepSize = 0;
const double iStart = -5, iEnd = 5;
volatile double intervalSize,threadStart;
/*
* Funktion, die integriert werden soll.
*/
double functionToIntegrate(double input) {
	return pow(input,3)+2*pow(input,2)-20*input+5;
}
/*
* Funktion, die von einem Thread ausgef�hrt wird.
*/
void integrate() {
	//F�hre Trapezregel aus.
	for (double s = threadStart; s<threadStart + intervalSize; s += stepSize) {
		sum += ((functionToIntegrate(s) + functionToIntegrate(s + stepSize)) / 2)*stepSize;
	}
	//Kommen noch weitere Intervalle, die bearbeitet werden m�ssen, hinter uns?
	if (threadCount > 0) {
		//Verringere die Anzahl der noch zu startenden Threads um eins. Der n�chste wird gleich gestartet.
		threadCount--;
		//Verschiebe den Startpunkt.
		threadStart += intervalSize;
		//Starte den Nachfolger
		thread afterRunner(integrate);
		//Und warte, bis dieser zu ende ist.
		afterRunner.join();
	}
}
int main(const int length,const char*args[]) {
	if (length < 2) {
		cout << "Wrong arguments"<<endl;
		return 0;
	}
	//Lese die anzahl der Threads ein.
	threadCount = stoi(args[1]);
	if (threadCount <= 0) {
		cout << "Wrong arguments" << endl;
		return 0;
	}
	//Lese die Schrittgr��e ein.
	stepSize = stod(args[2]);
	//Berechne Intervall�nge f�r einen einzelnen Thread.
	intervalSize = (iEnd - iStart) / threadCount;
	//Setze den Startpunkt.
	threadStart = iStart;
	//Verringere die Anzahl der noch zu startenden Threads um eins. Der erste wird gleich gestartet.
	threadCount--;
	//Starte den ersten Thread.
	thread runner(integrate);
	//Warte auf seine Beendigung.
	runner.join();
	cout << sum << endl;
	return 0;
}