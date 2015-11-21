#include "stopwatch.cpp"
int main(void) {
	StopWatch sw;
	sw.stop();
	sw.start();
	sw.start();
	for (int i = 0; i <1000000000; i++);
	std::cout << "Duration: " << sw.stop() << std::endl;
}