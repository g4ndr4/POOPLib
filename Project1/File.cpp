#include "File.h"


File::File(Person *p){
	member = p;
}

Person &File::getPerson() const{
	return *member;
}

bool File::addBorrowing(Borrowing b){
	borrowing_collection.addBorrowing(b);
	return true;
}

vector<Borrowing *> File::searchByReturnDate(Date current_date, Date borrowing_date, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	borrowing_collection.searchByReturnDate(current_date, borrowing_date, borrowing_count, borrowing_temp);
	return borrowing_temp;
}

vector<Borrowing *> File::searchByPeriod(Date date1, Date date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	borrowing_collection.searchByPeriod(date1, date2, borrowing_count, borrowing_temp);
	return borrowing_temp;
}
