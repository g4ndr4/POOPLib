#include "BorrowingCollection.h"

bool BorrowingCollection::addBorrowing(Borrowing b){
	borrowing_collection.push_back(b);
	return true;
}

vector<Borrowing *> BorrowingCollection::searchByReturnDate(ReturnDate current_date, BorrowedDate borrowing_date, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	for (vector<Borrowing>::iterator it = borrowing_collection.begin(); it != borrowing_collection.end(); ++it){
		if (it->getDate().getBorrowedDate() == borrowing_date && current_date > it->getDate().getReturnDate()){
			borrowing_temp.push_back(&(*it));
			cout << "Redni broj iznajmljivanja: " << borrowing_count + 1 << endl;
			cout << *it << endl;
			borrowing_count++;
		}
	}
	return borrowing_temp;
}

vector<Borrowing *> BorrowingCollection::searchByPeriod(BorrowedDate date1, BorrowedDate date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	for (vector<Borrowing>::iterator it = borrowing_collection.begin(); it != borrowing_collection.end(); ++it){
		if (date1 == it->getDate().getBorrowedDate() || date2 == it->getDate().getBorrowedDate() || (date1 < it->getDate().getBorrowedDate() && it->getDate().getBorrowedDate() < date2) || (date1 > it->getDate().getBorrowedDate() && it->getDate().getBorrowedDate() > date2)){
			borrowing_temp.push_back(&(*it));
			cout << "Redni broj iznajmljivanja: " << borrowing_count + 1 << endl;
			cout << *it << endl;
			borrowing_count++;
		}
	}
	return borrowing_temp;
}