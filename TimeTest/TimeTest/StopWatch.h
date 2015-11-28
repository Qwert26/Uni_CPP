#pragma once
#include <Time.h>
class StopWatch {
public:
	StopWatch();
	virtual ~StopWatch();
	void start(void);
	double stop(void);
private:
	bool started=false;
	clock_t zeitpunkt;
};