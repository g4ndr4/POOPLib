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

			void returnBook(string title);

			vector<Borrowing *> searchByTitle(string title);

			File *searchByReturnDate(Date current_date, Date borrowing_date);

			vector<Borrowing *> searchByPeriod(Date date1, Date date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp);
			bool addBorrowing(Borrowing b);

			friend ostream &operator<<(ostream &os, const File &f){
				return os;
			}
	};

#endif
