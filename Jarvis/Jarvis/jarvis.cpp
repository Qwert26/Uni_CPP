#include <fstream>
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <string>
#include <chrono>
using namespace std;
ifstream temperatureInput;
bool temperatureTerminated = false;
ifstream windowInput;
bool windowTerminated = false;
struct State {
	//Temperatur ok?
	bool temp=true;
	//Fenster offen?
	bool window=false;
	//Heizung an?
	bool heating=false;
	/*
	 Wandelt einen Status in eine Zahl um.
	 @return
	 Eine Zahl zwischen 0 bis 3, inklusive
	*/
	operator char() const {
		char ret = 0;
		ret += temp ? 2 : 0;
		ret += window ? 1 : 0;
		return ret;
	}
};
State prevState,currentState;
condition_variable cv;
mutex m;
/*
Hat sich der aktuelle Status gegenüber des vorherigen verändert oder sind beide Threads terminiert?
*/
bool updateOccured() noexcept {
	return (prevState.temp!=currentState.temp)|(prevState.window!=currentState.window)|(temperatureTerminated&windowTerminated);
}
/*
Liest alle 200ms einen neuen Temperaturwert ein.
*/
void temperatureReader() {
	double readed;
	//Gibt es noch etwas zum einlesen?
	while (temperatureInput) {
		temperatureInput >> readed;
		{
			unique_lock<mutex> lk(m);
			//Ist die Temperatur jetzt ok?
			if (readed >= 20) {
				currentState.temp = true;
			} else {
				currentState.temp = false;
			}
			//Sage allen Bescheid über den potentiellen neuen Status.
			cv.notify_all();
		}
		this_thread::sleep_for(200ms);
	}
	temperatureTerminated = true;
	//Sage den anderen Threads, dass du terminiert bist.
	cv.notify_all();
}
/*
Liest alle 500ms den aktuellen Fensterstatus ein.
*/
void windowReader() {
	string readed;
	//Gibt es noch etwas zum einlesen?
	while (windowInput) {
		windowInput >> readed;
		{
			unique_lock<mutex> lk(m);
			//Ist das Fenster jetzt offen?
			if (readed.compare("on") == 0) {
				currentState.window = true;
			} else {
				currentState.window = false;
			}
			//Sage allen Bescheid über den potentiellen neuen Status.
			cv.notify_all();
		}
		this_thread::sleep_for(500ms);
	}
	windowTerminated = true;
	//Sage den anderen Threads, dass du terminiert bist.
	cv.notify_all();
}
int main(const int length,const char*args[]) {
	if (length < 3) {
		cerr << "Not enough arguments!" << endl;
		return 0;
	}
	temperatureInput.open(args[1]);
	if (!temperatureInput.good()) {
		cerr << "Can not open temperature file!" << endl;
		return 0;
	}
	windowInput.open(args[2]);
	if (!windowInput.good()) {
		cerr << "Can not open window file!" << endl;
		return 0;
	}
	thread temperatureThread(temperatureReader);
	thread windowThread(windowReader);
	do {
		{
			unique_lock<mutex> lk(m);
			//Warte auf ein Update des aktuellen status.
			cv.wait(lk,updateOccured);
			//Erzeuge den Unterschied.
			const char diff = prevState.operator char()^currentState.operator char();
			switch (diff) {
				//Nichts hat sich verändert...
				case 0:
					break;
				//Das Fenster hat sich geändert.
				case 1:
					//Ist es jetzt offen?
					if (currentState.window) {
						cout << "window_open" << endl;
						//Sind wir am heitzen?
						if (currentState.heating) {
							cout << "switch heating off" << endl;
							currentState.heating = false;
						}
					} else {
						cout << "window_closed" << endl;
						//Müssen wir jetzt heizen?
						if (!currentState.temp) {
							cout << "switch heating on" << endl;
							currentState.heating = true;
						}
					}
					break;
				//Die Temperatur hat sich geändert.
				case 2:
					//Ist sie jetzt ok?
					if (currentState.temp) {
						cout << "temp_ok" << endl;
						//Sind wir am heizen?
						if (currentState.heating) {
							cout << "switch heating off" << endl;
							currentState.heating = false;
						}
					} else {
						cout << "temp_low" << endl;
						//Müssen wir jetzt heizen?
						if (!currentState.heating) {
							cout << "switch heating on" << endl;
							currentState.heating = true;
						}
					}
					break;
				//Beides hat sich geändert.
				case 3:
					switch(currentState.operator char()) {
						//Temperatur nicht ok und Fenster nicht auf.
						case 0:
							cout << "temp_low" << endl << "window_closed" << endl;
							//Müssen wir heizen?
							if (!currentState.heating) {
								cout << "switch heating on" << endl;
								currentState.heating = true;
							}
							break;
						//Temperatur nicht ok und Fenster auf.
						case 1:
							cout << "temp_low" << endl << "window_open" << endl;
							//Sind wir am heizen?
							if (currentState.heating) {
								cout << "switch heating off" << endl;
								currentState.heating = false;
							}
							break;
						//Temperatur ok und Fenster nicht auf.
						case 2:
							cout << "temp_ok" << endl << "window_closed" << endl;
							//Sind wir am heizen?
							if (currentState.heating) {
								cout << "switch heating off" << endl;
								currentState.heating = false;
							}
							break;
						//Temperatur ok und Fenster auf.
						case 3:
							cout << "temp_ok" << endl << "window_open" << endl;
							//Sind wir am heizen?
							if (currentState.heating) {
								cout << "switch heating off" << endl;
								currentState.heating = false;
							}
							break;
						default:
							cerr << "Ein Debugger hat den Return-Wert des operators geändert!" << endl;
							break;
					}
					break;
				default:
					cerr << "Ein Debugger hat die variable diff geändert!" << endl;
					break;
			}
			//Setze den vorherigen Status auf den aktuellen.
			prevState.heating = currentState.heating;
			prevState.temp = currentState.temp;
			prevState.window = currentState.window;
		}
	} while (!(temperatureTerminated&windowTerminated));
	//Safety joins
	temperatureThread.join();
	windowThread.join();
	return 0;
}