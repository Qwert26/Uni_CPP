#pragma once
#include <iostream>
class StaticBase {
public:
	static int i;
	static void myFunc(void) {
		#ifdef VERBOSE
		std::cout << "Called " << typeid(StaticBase).name() << "::" << __func__ << std::endl;
		#endif
		StaticBase::i++;
	}
};