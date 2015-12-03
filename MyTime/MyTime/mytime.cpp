#include "mytime.h"
#include <iostream>
MyTime::MyTime(int hours=0,int minutes=0,int seconds=0) {
	this->seconds = seconds % 60;
	this->minutes = minutes + seconds / 60;//Möglicherweise >=60
	this->hours = hours + this->minutes / 60;
	this->minutes %= 60;
}
MyTime::~MyTime() {
	hours = minutes = seconds = 0;
}
const int MyTime::getHour(void) {
	return hours;
}
const int MyTime::getMinute(void) {
	return minutes;
}
const int MyTime::getSecond(void) {
	return seconds;
}
MyTime MyTime::operator+(const MyTime& other) {
	return MyTime(hours+other.hours,minutes+other.minutes,seconds+other.seconds);
}
MyTime MyTime::operator+(const int other) {
	return MyTime(hours,minutes,seconds+other);
}
MyTime operator+(const int i,const MyTime& time) {
	return MyTime(time.hours,time.minutes,time.seconds+i);
}
MyTime& MyTime::operator+=(const MyTime& other) {
	seconds += other.seconds;//Möglicherweise >=60
	minutes += other.minutes + seconds / 60;//Möglicherweise >=60
	seconds %= 60;
	hours += other.hours + minutes / 60;
	minutes %= 60;
	return *this;
}
MyTime& MyTime::operator+=(const int other) {
	seconds += other;//Möglicherweise >=60
	minutes += seconds / 60;//Möglicherweise >=60
	seconds %= 60;
	hours += minutes / 60;
	minutes %= 60;
	return *this;
}
MyTime::operator int() const {
	return seconds + 60 * (minutes + 60 * hours);
}
std::ostream& operator<<(std::ostream& o,MyTime& time) {
	o << time.getHour() << ':' << time.getMinute() << ':' << time.getSecond();
	return o;
}