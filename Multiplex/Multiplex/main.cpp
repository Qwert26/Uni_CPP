#include "PureBase.h"
#include "StaticBase.h"
#include "VirtBase.h"
#include "VirtDer.h"
#include "StopWatch.h"
#define MEASURETIME(description,repetitions,instructions2test)	{StopWatch sw;\
																sw.start();\
																for(int i=0;i<repetitions;i++) {instructions2test}\
																std::cout<<"My computer requires "<<sw.stop()<<" seconds to execute "<<description<<" "<<repetitions<<" times.\n";}
int main(void) {
	PureBase pure;
	VirtBase vbase;
	VirtDer vder;
	PureBase *ppure = new PureBase();
	VirtBase *pvbase = new VirtBase();
	VirtDer *pvder = new VirtDer();
	VirtBase *pvbaseder = pvder;

	StaticBase::myFunc();
	pure.myFunc();
	vbase.nvFunc();
	vbase.virtFunc();
	vder.myFunc();
	vder.nvFunc();
	vder.virtFunc();
	(*ppure).myFunc();
	(*pvbase).nvFunc();
	(*pvbase).virtFunc();
	(*pvder).myFunc();
	(*pvder).nvFunc();
	(*pvder).virtFunc();
	(*pvbaseder).nvFunc();
	(*pvbaseder).virtFunc();
}