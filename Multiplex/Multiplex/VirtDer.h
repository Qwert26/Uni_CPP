#pragma once
#include "VirtBase.h"
class VirtDer : public VirtBase {
private:
	int i;
public:
	VirtDer();
	void myFunc(void);
	virtual void virtFunc(void);
};