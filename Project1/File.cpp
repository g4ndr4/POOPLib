#include "File.h"


File::File(Person *p){
	person = p;
	membership_id = p->getMembershipID()->getMid();
	member = true;
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

void File::setMember(bool m){
	member = m;
}

int File::getMembershipID() const{
	return membership_id;
}

Person *File::getPerson() const{
	return person;
}

Borrowing *File::getBorrowing(int index){
	return borrowing_collection.getBorrowing(index);
}

vector<Borrowing *> *File::searchBorrowings(){
	return borrowing_collection.getBorrowingCollection();
}

bool File::isMember() const{
	return member;
}

bool File::hasActiveBorrowings() const{
	return borrowing_collection.hasActiveBorrowings();
}

bool File::addBorrowing(Borrowing *b){
	borrowing_collection.addBorrowing(b);
	return true;
}

File *File::searchByReturnDate(Date current_date, Date borrowing_date){
	if (borrowing_collection.searchByReturnDate(current_date, borrowing_date)) return this;
	else return nullptr;
}

File *File::searchByPeriod(Date period_begin, Date period_end){
	if (borrowing_collection.searchByPeriod(period_begin, period_end)) return this;
	else return nullptr;
}
