#include "SubscribeMember.h"


SubscribeMember::SubscribeMember(Person *p, Library *l) : ModifyMember(l){
	person = p;
}


SubscribeMember::~SubscribeMember(){}

Result *SubscribeMember::execute(){
	library->subscribeMember(person);
	return nullptr;
}
