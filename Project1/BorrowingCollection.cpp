#include "BorrowingCollection.h"

bool BorrowingCollection::addBorrowing(Borrowing b){
	borrowing_collection.push_back(b);
	return true;
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

vector<Borrowing *> BorrowingCollection::searchByPeriod(Date date1, Date date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp){
	for (vector<Borrowing>::iterator it = borrowing_collection.begin(); it != borrowing_collection.end(); ++it){
		if (date1 == it->getBorrowedDate() || date2 == it->getBorrowedDate() || (date1 < it->getBorrowedDate() && it->getBorrowedDate() < date2) || (date1 > it->getBorrowedDate() && it->getBorrowedDate() > date2)){
			borrowing_temp.push_back(&(*it));
			cout << "Redni broj iznajmljivanja: " << borrowing_count + 1 << endl;
			cout << *it << endl;
			borrowing_count++;
		}
	}
	return borrowing_temp;
}