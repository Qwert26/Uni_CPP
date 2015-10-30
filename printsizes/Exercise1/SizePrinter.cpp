#include <stdio.h>
int main(void) {
	printf("char %zd\n",sizeof(char));
	printf("short %zd\n",sizeof(short));
	printf("int %zd\n",sizeof(int));
	printf("long %zd\n", sizeof(long));
	printf("long long %zd\n", sizeof(long long));
	printf("float %zd\n", sizeof(float));
	printf("double %zd\n", sizeof(double));
	printf("long double %zd\n", sizeof(long double));
	char ptr=0;
	printf("pointer %zd\n",sizeof(&ptr));
	//Die L�nge eines Pointers ist unabh�ngig von der L�nge des Datentyps, auf die er zeigt, aber nicht von der Prozessorstruktur!
	return 0;
}