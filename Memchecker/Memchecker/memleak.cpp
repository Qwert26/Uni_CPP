#include "memcheck.h"
class A {
	int *a;
public:
	A(int v = 0) {
		a = new int;
		*a = v;
	}
	~A() {
		delete a;
	}
};
void test(void) {
	int *b = new int;
	*b = 42;
	A x(*b);
}
int main(void) {
	int *x = new int[10];
	x[0] = 1;
	x[1] = 2;
	x[2] = 4;
	A i;
	A j(10);
	test();
	i = j;
	delete x;
	memchecker_print_allocated();
}