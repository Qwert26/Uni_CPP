#include "PureBase.h"
#include "VirtBase.h"
#include "VirtDer.h"
#include "StopWatch.h"
#include <iostream>
#ifdef TASK02
#define MEASURETIME(description,repetitions,instructions2test)	{StopWatch sw;\
																sw.start();\
																for(int i=0;i<repetitions;i++) {instructions2test}\
																std::cout<<"My computer requires "<<sw.stop()<<" seconds to execute "<<description<<" "<<repetitions<<" times.\n";}
#endif
int main(void) {
	PureBase pure;
	VirtBase vbase;
	VirtDer vder;
	PureBase *ppure = new PureBase();
	VirtBase *pvbase = new VirtBase();
	VirtDer *pvder = new VirtDer();
	VirtBase *pvbaseder = pvder;
	//Beginn Aufgabe 1a:
	#ifdef VERBOSE
		//Direkter Aufruf der Methode
		pure.myFunc();
		vbase.nvFunc();
		vbase.virtFunc();
		vder.myFunc();
		vder.nvFunc();
		vder.virtFunc();

		std::cout << "using pointers to call functions."<<std::endl;

		//Derefenzierter Aufruf der Methode. Gleichbedeutend mit ->
		(*ppure).myFunc();
		(*pvbase).nvFunc();
		(*pvbase).virtFunc();
		(*pvder).myFunc();
		(*pvder).nvFunc();
		(*pvder).virtFunc();
		(*pvbaseder).nvFunc();
		(*pvbaseder).virtFunc();
	#endif
	//Beginn Aufgabe 1b:
	#ifdef TASK02
		MEASURETIME("pure.myFunc()", 50000000, pure.myFunc();)
		MEASURETIME("vbase.nvFunc()", 50000000, vbase.nvFunc();)
		MEASURETIME("vbase.virtFunc()", 50000000, vbase.virtFunc();)
		MEASURETIME("vder.myFunc()", 50000000, vder.myFunc();)
		MEASURETIME("vder.nvFunc()", 50000000, vder.nvFunc();)
		MEASURETIME("vder.virtFunc()", 50000000, vder.virtFunc();)

		MEASURETIME("(*ppure).myFunc()", 50000000, (*ppure).myFunc();)
		MEASURETIME("(*pvbase).nvFunc()", 50000000, (*pvbase).nvFunc();)
		MEASURETIME("(*pvbase).virtFunc()", 50000000, (*pvbase).virtFunc();)
		MEASURETIME("(*pvder).myFunc()", 50000000, (*pvder).myFunc();)
		MEASURETIME("(*pvder).nvFunc()", 50000000, (*pvder).nvFunc();)
		MEASURETIME("(*pvder).virtFunc()", 50000000, (*pvder).virtFunc();)
		MEASURETIME("(*pvbaseder).nvFunc()", 50000000, (*pvbaseder).nvFunc();)
		MEASURETIME("(*pvbaseder).virtFunc()", 50000000, (*pvbaseder).virtFunc();)
	#endif
	//Beginn Aufgabe 1c:
	#ifdef TASK03
		//Der dc überprüft ebenfalls, ob das Downcasten funktioniert. In Java: instanceof
		VirtDer* casted = dynamic_cast<VirtDer*>(pvbaseder);
		//Hat es funktioniert?
		if (casted) {
			casted->myFunc();
		} else {
			std::cerr << "Conversion failed!";
		}
		//Der sc überprüft nicht die Typsicherheit!
		casted = static_cast<VirtDer*>(pvbaseder);
		//Manuelle Überprüfung
		if (typeid(*casted) == typeid(VirtDer)) {
			casted->myFunc();
		} else {
			std::cerr << "Conversion failed!";
		}
	#endif
}