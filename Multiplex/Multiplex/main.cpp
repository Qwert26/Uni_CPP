#include "PureBase.h"
#include "StaticBase.h"
#include "VirtBase.h"
#include "VirtDer.h"
int main(void) {
	PureBase pure;
	VirtBase vbase;
	VirtDer vder;
	PureBase *ppure = new PureBase();
	VirtBase *pvbase = new VirtBase();
	VirtDer *pvder = new VirtDer();
	VirtBase *pvbaseder = pvder;

	//StaticBase::myFunc();
	pure.myFunc();
	vbase.nvFunc();
	vbase.virtFunc();
	vder.myFunc();
	vder.nvFunc();
	vder.virtFunc();
}