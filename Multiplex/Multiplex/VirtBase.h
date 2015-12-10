#pragma once
class VirtBase {
private:
	int i;
public:
	VirtBase();
	void nvFunc(void);
	virtual void virtFunc(void);
};