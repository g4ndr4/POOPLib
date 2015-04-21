#include "File.h"


File::File(Person *p){
	member = p;
}

void File::returnBook(string title){
	vector<Borrowing *> borrowing_temp;
	int borrowing_count = 0;
	borrowing_collection.returnBook(title, borrowing_count, borrowing_temp);
	int index = 0;
	cout << "Unesite redni broj pozajmice koju zelite da razduzite: "; cin >> index;
	borrowing_temp[index-1]->getBook()->setBorrow(nullptr);
	borrowing_temp[index-1]->returnBook();
}

Person &File::getPerson() const{
	return *member;
}

bool File::addBorrowing(Borrowing b){
	borrowing_collection.addBorrowing(b);
	return true;
}

File *File::searchByReturnDate(Date current_date, Date borrowing_date){
	if (borrowing_collection.searchByReturnDate(current_date, borrowing_date)) return this;
	else return nullptr;
}

vector<Borrowing *> File::searchByPeriod(Date date1, Date date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	borrowing_collection.searchByPeriod(date1, date2, borrowing_count, borrowing_temp);
	return borrowing_temp;
}
