#pragma once
#ifndef _Date_H_
	#define _Date_H_
	#include "iostream"
	using namespace std;

	class Date{
	private:
		int year;
		int month;
		int day;
	public:

		Date(int d, int m, int y);

		//set

		void setYear(int y);
		void setMonth(int m);
		void setDay(int d);

		//get

		int getYear() const;
		int getMonth() const;
		int getDay() const;

		//pomocne metode

		friend bool operator == (Date &d1, Date &d2){
			if (d1.getDay() == d2.getDay() && d1.getMonth() == d2.getMonth() && d1.getYear() == d2.getYear()) return true;
			else return false;
		}

		friend bool operator != (Date &d1, Date &d2){
			if (d1 == d2) return false;
			else return true;
		}

		friend bool operator < (Date &d1, Date &d2){	
			if (d1.getYear() < d2.getYear() || (d1.getYear() == d2.getYear() && d1.getMonth() < d2.getMonth()) || (d1.getYear() == d2.getYear() && d1.getMonth() == d2.getMonth() && d1.getDay() < d2.getDay()) return true;
			else return false;
		}

		friend bool operator > (Date &d1, Date &d2){
			if (d1 == d2 || d1 < d2) return false;
			else return true;
		}

		friend ostream &operator<<(ostream &os, const Date &d){
			os << d.getDay() << '.' << d.getMonth() << '.' << d.getYear() << '.';
			return os;
		}
	};
#endif