#pragma once
class SecArr {
private:
	int* start;
	int* current;
	int* end;
public:
	//Konstruktoren
	SecArr(int*,int*);
	//Dekonstruktor
	virtual ~SecArr();
	//Operatoren
	int& operator[](int i);
	int& operator*();
	SecArr& operator++();
	SecArr& operator--();
	SecArr operator++(int);
	SecArr operator--(int);
};