#include "MembershipID.h"


MembershipID::MembershipID(PersonalID &pid){
	curID++;
	id = curID;
}


int MembershipID::getMid() const{
	return id;
}

int MembershipID::curID = 0;