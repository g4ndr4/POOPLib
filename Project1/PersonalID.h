#pragma once
#ifndef _PersonalID_H_
#define _PersonalID_H_
	#include "iostream"
	#include "cmath"
	#include "string"
	using namespace std;
	class PersonalID{
		private:
			string name;
			string surname;
			long jmbg;
		public:
			PersonalID(string n, string s, long j);
			long getJmbg() const;
			friend ostream &operator<<(ostream &os, const PersonalID &pid){
				os << "JMBG: " << pid.jmbg << endl;
				return os;
			}
	};
#endif