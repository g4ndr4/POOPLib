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

// pomocne metode

Date *Date::calculateReturnDate(int period) const {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
		if ((day + period) > 31){
			return new Date((day + period - 31), month + 1, year);
		}
		else return new Date((day + period), month, year);
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11){
		if ((day + period) > 30){
			return new Date((day + period - 30), month + 1, year);
		}
		else return new Date((day + period), month, year);
	}
	else if (month == 12){
		if ((day + period) > 31){
			return new Date((day + period - 31), 1, year + 1);
		}
		else return new Date((day + period), month, year);
	}
	else{
		if ((day + period) <= 28){
			return new Date((day + period), month, year);

		}
		else{
			if (year % 4 == 0 || year % 400 == 0){
				if ((day + period) > 29){
					return new Date((day + period - 29), month + 1, year);
				}
				else return new Date((day + period), month, year);
			}
			else{
				if ((day + period) > 28){
					return new Date((day + period - 28), month + 1, year);
				}
				else return new Date((day + period), month, year);
			}
		}
	}
}

