#include "UnsubscribeMember.h"


UnsubscribeMember::UnsubscribeMember(int mID, Library *l) : ModifyMember(l){
	membership_id = mID;
}

UnsubscribeMember::~UnsubscribeMember(){}

void UnsubscribeMember::undo(){
	person->setMembershipID(mID);
	library->subscribeMember(person);
}

Result *UnsubscribeMember::execute(){
	person = library->unsubscribeMember(membership_id);
	if (person){
		mID = person->getMembershipID();
		person->setMembershipID(nullptr);
		return nullptr;
	}
	else return nullptr;
}