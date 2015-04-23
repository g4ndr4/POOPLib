#include "SearchBorrowings.h"


SearchBorrowings::SearchBorrowings(int mID, Library *l) : SearchingOperation(l){
	membership_id = mID;
}


SearchBorrowings::~SearchBorrowings(){}

Result *SearchBorrowings::execute(){
	return new BorrowingResult(library->searchFilesByMembershipID(membership_id)->searchBorrowings());
}
