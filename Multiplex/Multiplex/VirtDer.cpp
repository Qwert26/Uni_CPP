#include "VirtDer.h"
#include <iostream>
VirtDer::VirtDer() {
	i = 0;
}
void VirtDer::myFunc(void) {
	#ifdef VERBOSE
	std::cout << "Called " << typeid(*this).name() << "::" << __func__ << std::endl;
	#endif
	i++;
}
void VirtDer::virtFunc(void) {
	#ifdef VERBOSE
	std::cout << "Called " << typeid(*this).name() << "::" << __func__ << std::endl;
	#endif
	i++;
}