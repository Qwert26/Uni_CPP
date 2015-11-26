#include <iostream>
/*
Von einer Website abgeguckt, nur den Vergleichsoperator vertauscht.
*/
#define MAXM(A,B) (A<B?B:A)
/*
Nimmt zwei ints und gibt das groessere zurueck.
*/int maxf(int a,int b) {
	std::cout << "In maxf(int)" <<std::endl;
	if (a>b) {
		return a;
	} else {
		return b;
	}
}
/*
Nimmt zwei doubles und gibt das groessere zurueck.
*/double maxf(double a,double b) {
	std::cout << "In maxf(double)" << std::endl;
	if (a>b) {
		return a;
	} else {
		return b;
	}
}
int main(void) {
	int a = 10, b = 20;
	std::cout << "MAXM1 = " << MAXM(a, b) << std::endl;
	std::cout << "MAXM2 = " << MAXM(a, b + 0.2) << std::endl;
	std::cout << "MAXM3 = " << MAXM(a, b++) << std::endl;
	std::cout << "maxf1 = " << maxf(a, b) << std::endl;
	// what's the problem with the following line?
	//std::cout << "maxf = " << maxf((double)a,b+0.2) << std::endl;
	std::cout << "maxf2 = " << maxf(a + 0.1, b + 0.2) << std::endl;
	std::cout << "maxf3 = " << maxf(a, b++) << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
}
//BRAUCHE UMLAUTE!