#include "PureBase.h"
#include <iostream>
PureBase::PureBase() {
	i = 0;
}
void PureBase::myFunc(void) {
	#ifdef VERBOSE
	std::cout << "Called " << typeid(*this).name() << "::" << __func__ << std::endl;
	#endif
	i++;
}