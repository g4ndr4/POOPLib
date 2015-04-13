#include "Date.h"

//konstruktori i destruktori

Date::Date(int d, int m, int y){
	day = d;
	month = m;
	year = y;
}

//set

void Date::setYear(int y){
	year = y;
}

void Date::setMonth(int m){
	month = m;
}

void Date::setDay(int d){
	day = d;
}

//get

int Date::getYear() const{
	return year;
}

int Date::getMonth() const{
	return month;
}

int Date::getDay() const{
	return day;
}
