#include "File.h"


File::File(Person *p){
	member = p;
}

Person &File::getPerson() const{
	return *member;
}

//Z10
bool File::addBorrowing(Borrowing b){
	borrowing_collection.addBorrowing(b);
	return true;
}

vector<Borrowing *> File::searchByReturnDate(ReturnDate current_date, BorrowedDate borrowing_date, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	borrowing_collection.searchByReturnDate(current_date, borrowing_date, borrowing_count, borrowing_temp);
	return borrowing_temp;
}

vector<Borrowing *> File::searchByPeriod(BorrowedDate date1, BorrowedDate date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	borrowing_collection.searchByPeriod(date1, date2, borrowing_count, borrowing_temp);
	return borrowing_temp;
}
