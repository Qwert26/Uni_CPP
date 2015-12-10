#include "StaticBase.h"
#include <iostream>
void StaticBase::myFunc(void) {
	#ifdef VERBOSE
	std::cout << "Called " << typeid(*this).name() << "::" << __func__ << std::endl;
	#endif
	StaticBase::i++;
}