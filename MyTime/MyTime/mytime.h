#pragma once
#include <iostream>
class MyTime {
private:
	int hours, minutes, seconds;
public:
	//Konstruktoren
	MyTime(int,int,int);
	//Dekonstruktor
	virtual ~MyTime();
	//Methoden
	const int getHour(void);
	const int getMinute(void);
	const int getSecond(void);
	//Operatoren
	MyTime operator+(const MyTime&);
	MyTime operator+(const int);
	friend MyTime operator+(const int,const MyTime&);
	MyTime& operator+=(const MyTime&);
	MyTime& operator+=(const int);
	friend std::ostream& operator<<(std::ostream&,MyTime&);
	operator int() const;
};