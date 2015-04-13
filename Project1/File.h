#pragma once
#ifndef _File_H_
#define _File_H_
	#include "Person.h"
	#include "BorrowingCollection.h"
	#include "iostream"
	#include "Date.h"

	using namespace std;
	
	class File{
		private:
			Person *member;
			BorrowingCollection borrowing_collection;
		public:
			File(Person *p);

			Person &getPerson() const;

			vector<Borrowing *> searchByReturnDate(ReturnDate current_date, BorrowedDate borrowing_date, int &borrowing_count, vector<Borrowing *> &borrowing_temp);

			vector<Borrowing *> searchByPeriod(BorrowedDate date1, BorrowedDate date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp);
			bool addBorrowing(Borrowing b);
	};

#endif
