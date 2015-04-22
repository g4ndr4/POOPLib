#include "BorrowingCollection.h"

bool BorrowingCollection::addBorrowing(Borrowing b){
	borrowing_collection.push_back(b);
	return true;
}

bool BorrowingCollection::hasActiveBorrowings() const{
	for (auto it : borrowing_collection){
		if (it.getBook() != nullptr) return true;
	}
	return false;
}

vector<Borrowing> *BorrowingCollection::getBorrowingCollection(){
	return &borrowing_collection;
}

Borrowing *BorrowingCollection::getBorrowing(int index){
	return &(borrowing_collection.at(index));
}

void BorrowingCollection::returnBook(string title, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	for (vector<Borrowing>::iterator it = borrowing_collection.begin(); it != borrowing_collection.end(); ++it){
		if (it->getBook()->getTitle() == title) {
			borrowing_temp.push_back(&(*it));
			cout << endl << "Redni broj pozajmice: " << borrowing_count + 1 << endl << endl;
			cout << *it << endl;
			borrowing_count++;
		}
	}
}

bool BorrowingCollection::searchByReturnDate(Date current_date, Date borrowing_date){
	for (auto it : borrowing_collection) if (it.getBorrowedDate() == borrowing_date && current_date > it.getReturnDate()) return true;
	return false;
}

bool BorrowingCollection::searchByPeriod(Date period_begin, Date period_end){
	for (auto it : borrowing_collection) if (period_begin == it.getBorrowedDate() || period_end == it.getBorrowedDate() ||
											(period_begin < it.getBorrowedDate() && it.getBorrowedDate() < period_end) ||
											(period_begin > it.getBorrowedDate() && it.getBorrowedDate() > period_end)) return true;
	return false;
}