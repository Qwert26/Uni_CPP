#include <stdio.h>
//Deklarationen
void deeper(unsigned long long level);
//Implementierungen
int main(void) {
	deeper(1);
	//Der Stackoverflow wird kommen, bevor return erreicht wird!
	return -1;
}
void deeper(unsigned long long level) {
	printf("Stacksize is now %lli levels deep\n",level);
	deeper(level + 1);
}