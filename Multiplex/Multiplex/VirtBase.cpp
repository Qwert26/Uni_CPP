#include "VirtBase.h"
#include <iostream>
VirtBase::VirtBase() {
	i = 0;
}
void VirtBase::nvFunc(void) {
	#ifdef VERBOSE
	std::cout << "Called " << typeid(*this).name() << "::" << __func__ << std::endl;
	#endif
	i++;
}
void VirtBase::virtFunc(void) {
	#ifdef VERBOSE
	std::cout << "Called " << typeid(*this).name() << "::" << __func__ << std::endl;
	#endif
	i++;
}