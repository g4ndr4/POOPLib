#include "BorrowBook.h"


BorrowBook::BorrowBook(Book *b, int mID, Date bd, Date rd, Library *l) : book(b), borrowed_date(bd), return_date(rd), ModifyBook(l){
	membership_id = mID;
}


BorrowBook::~BorrowBook(){}

Result *BorrowBook::execute(){
	(library->searchFilesByMembershipID(membership_id))->addBorrowing(Borrowing(borrowed_date, return_date, book));
	return nullptr;
}