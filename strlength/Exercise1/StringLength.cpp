#include <stdio.h>
/**
Zählt die Anzahl der Zeichen in einer Zeichenkette.
@param *start Zeiger für die Startadresse der Zeichenkette.
@return die Anzahl der Zeichen ohne das Nullzeichen
*/
int countChars(char*start) {
	int count = 0;
	//Zähle so lange, bis der Zeiger auf das Nullzeichen zeigt.
	while(*start!=0) {
		count++;
		start++;
	}
	return count;
}
/**
Berechnet die Anzahl der Zeichen in einer Zeichenkette.
@param *start Zeiger für die Startadresse der Zeichenkette.
@return die Anzahl der Zeichen ohne das Nullzeichen
*/
int calcChars(char*start) {
	char*end = start;
	//Gehe zum Nullzeichen
	while(*end!=0) {
		end++;
	}
	//(Endadresse-Startadresse)/sizeof(char) Die Division erfolgt automatisch!
	return end - start;
}
int main(int argc,char* argv[]) {
	if(argc==2) {
		printf("%d\n",countChars(argv[1]));
		printf("%d\n",calcChars(argv[1]));
	} else {
		printf("wrong input");
	}
	return 0;
}