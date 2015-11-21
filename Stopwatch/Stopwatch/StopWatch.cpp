#include <time.h>
#include <iostream>
class StopWatch {
	private:
		bool started = false;
		clock_t zeitPunkt;
	public:
		void start(void) {
			if (started) {
				std::cout << "StopWatch already running!\n";
			} else {
				zeitPunkt=clock();
				started = true;
			}
		}
		double stop(void) {
			if (started) {
				zeitPunkt = clock() - zeitPunkt;
				started = false;
				return (double)zeitPunkt/(double)CLOCKS_PER_SEC;
			} else {
				std::cout << "StopWatch not started yet!\n";
			}
		}
};