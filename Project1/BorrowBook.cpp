#include "BorrowBook.h"


BorrowBook::BorrowBook(Book *b, int mID, Date bd, Date rd, Library *l) : book(b), borrowed_date(bd), return_date(rd), ModifyBook(l){
	membership_id = mID;
}


BorrowBook::~BorrowBook(){}

Result *BorrowBook::execute(){
	Borrowing *borrowing = new Borrowing(borrowed_date, return_date, book);
	(library->searchFilesByMembershipID(membership_id))->addBorrowing(borrowing);
	return nullptr;
}