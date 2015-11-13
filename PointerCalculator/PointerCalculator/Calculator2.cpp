#include <stdio.h>
#include <stdlib.h>
int add(int a,int b) {
	return a + b;
}
int subtract(int a,int b) {
	return a - b;
}
int multiply(int a, int b) {
	return a*b;
}
int divide(int a, int b) {
	return a / b;
}
int main(int argc,char* argv[]) {
	if (argc>=4) {
		int a = atoi(argv[1]),b=atoi(argv[3]);
		char op = *argv[2];
		/*
		'+'=43=>0=>0
		'-'=45=>2=>1
		'/'=47=>4=>2
		'X'=88=>45=>22
		'x'=120=>77=>38
		char=decimal value=>-43=>/2
		Der größte Index der Jump Table wird 38 sein, daher ist die Länge 39
		*/
		int (*jumpTable[39])(int,int);
		//Safety first!
		for (char i = 0; i < 39;i++) {
			jumpTable[i] = NULL;
		}
		//register functions
		jumpTable[0] = add;
		jumpTable[1] = subtract;
		jumpTable[2] = divide;
		jumpTable[22] = jumpTable[38] = multiply;
		//Gueltiger Operator?
		if ((op=='+')|(op=='-')|(op=='/')|(op=='x')|(op=='X')) {
			printf("%i %c %i = %i\n",a,op,b,jumpTable[(op-43)/2](a,b));
		} else {
			printf("Not supported Operator!\n");
		}
	} else {
		printf("Not enough Arguments!\n");
	}
	return 0;
}