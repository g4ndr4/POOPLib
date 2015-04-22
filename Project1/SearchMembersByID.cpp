#include "SearchMembersByID.h"


SearchMembersByID::SearchMembersByID(int mID, Library *l) : SearchMembers(l){
	membership_id = mID;
}


SearchMembersByID::~SearchMembersByID(){}

Result *SearchMembersByID::execute(){
//	return new MemberResult(library->fi(membership_id));
	return nullptr;
}