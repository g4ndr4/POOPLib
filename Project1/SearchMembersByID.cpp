#include "SearchMembersByID.h"


SearchMembersByID::SearchMembersByID(int mID, Library *l) : SearchMembers(l){
	membership_id = mID;
}


SearchMembersByID::~SearchMembersByID(){}

Result *SearchMembersByID::execute(){
	vector<File *> *temp_vect = new vector<File *>;
	temp_vect->push_back(library->searchFilesByMembershipID(membership_id));
	return new MemberResult(temp_vect);
}