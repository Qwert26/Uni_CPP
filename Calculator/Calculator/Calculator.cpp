#include <stdio.h>
//compile with /W3
#pragma warning(disable:4996)
int main(void) {
	int a,b,count;
	char op;
	char input[128];
	while(true) {
		printf("Enter <int> <op> <int>, single '0' to exit: ");
		fgets(input,128,stdin);
		//Wie viele UEbereinstimmung haben wir?
		count=sscanf(input,"%i %c %i",&a,&op,&b);
		//Eine UEbereinstimmung und a ist 0: Beenden!
		if (count==1&&a==0) {
			printf("Goodbye\n");
			return 0;
		} /*Nicht 3 UEbereinstimmungen*/ else if (count!=3) {
			printf("invalid input\n");
		} /*Genau 3 UEbereinstimmungen*/ else {
			switch (op) {
			case '+':
				printf("%i %c %i = %i\n",a,op,b,a+b);
				break;
			case '-':
				printf("%i %c %i = %i\n", a, op, b, a - b);
				break;
			case '*':
				printf("%i %c %i = %i\n", a, op, b, a * b);
				break;
			case '/':
				if (b) {
					printf("%i %c %i = %i\n", a, op, b, a / b);
				} else {
					printf("invalid input\n");
				}
				break;
			// Illegaler Operator obwohl % ein gültiger wäre...
			default:
				printf("invalid input\n");
			}
		}
	}
}