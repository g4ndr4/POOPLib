#include "SubscribeMember.h"


SubscribeMember::SubscribeMember(Person *p, Library *l) : ModifyMember(l){
	person = p;
}


SubscribeMember::~SubscribeMember(){}

void SubscribeMember::undo(){
	library->unsubscribeMember(person->getMembershipID()->getMid());
	person->setMembershipID(nullptr);
	return;
}

Result *SubscribeMember::execute(){
	library->subscribeMember(person);
	return nullptr;
}
