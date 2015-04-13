#include "PersonalID.h"


PersonalID::PersonalID(string n, string s, long j){
	name = n;
	surname = s;
	jmbg = j;
}

long PersonalID::getJmbg() const{
	return jmbg;
}