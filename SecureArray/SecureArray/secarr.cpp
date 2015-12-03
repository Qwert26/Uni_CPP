#include "secarr.hpp"
#include <iostream>
using namespace std;
SecArr::SecArr(int* start,int* end) {
	if (start > end) {
		cout << "start is behind end!\n";
		this->start=this->end = end;
	} else {
		this->start = start;
		this->end = end;
	}
	current = this->start;
}
SecArr::~SecArr() {
	start = current = end = nullptr;
}
int& SecArr::operator[](int i) {
	int* target = current + i;
	if (target > end) {
		target = end;
		cout << "Clamping to end!\n";
	} else if (target < start) {
		target = start;
		cout << "Clamping to start!\n";
	}
	return *current;
}
int& SecArr::operator*() {
	return *current;
}
SecArr& SecArr::operator++() {
	if (current < end) {
		current++;
	} else {
		cout << "Invalid index\n";
	}
	return *this;
}
SecArr & SecArr::operator--() {
	if (current > start) {
		current--;
	} else {
		cout << "Invalid index\n";
	}
	return *this;
}
SecArr SecArr::operator++(int) {
	SecArr ret(*this);
	operator++();
	return ret;
}
SecArr SecArr::operator--(int) {
	SecArr ret(*this);
	operator--();
	return ret;
}