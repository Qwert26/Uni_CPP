#include <stdio.h>

int main(int argc,char* argv[]) {
	if(argc==1) {
		printf(argv[0]);
	} else {
		printf("wrong input");
	}
	return 0;
}