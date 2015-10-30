#include<stdio.h>
#include<stdlib.h>
struct rawFloat {
	unsigned int mantissa : 23;		//000000000???????????????????????
	unsigned int exponent : 8;		//0????????00000000000000000000000
	//Sign ist leider zu viel...
	//unsigned char sign : 1;			//?0000000000000000000000000000000
};
union floatReader {
	float f;
	rawFloat rf;
	signed int bits;
};
int main(int argc,char*argv[]) {
	if (argc == 2) {
		floatReader input = {0};
		input.f=atof(argv[1]);
		printf("Input: %f\n",input.f);
		printf("Raw: %08X\n",input.bits);
		char sign = (input.bits>0) ? '+' : '-' ;
		printf("Sign: %c, Exponent: %d,Mantissa: %X",sign,input.rf.exponent,input.rf.mantissa);
	} else {
		printf("wrong input");
	}
	return 0;
}