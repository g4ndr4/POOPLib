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
			Person *person;
			bool member;
			int membership_id;
			BorrowingCollection borrowing_collection;
		public:
			File(Person *p);

			void setMember(bool m);

			int getMembershipID() const;

			Person *getPerson() const;
			Borrowing *getBorrowing(int index);

			vector<Borrowing *> *searchBorrowings();

			bool addBorrowing(Borrowing *b);
			
			bool isMember() const;

			bool hasActiveBorrowings() const;

			void returnBook(string title);

			vector<Borrowing *> searchByTitle(string title);

			File *searchByReturnDate(Date current_date, Date borrowing_date);

			File *searchByPeriod(Date period_begin, Date period_end);
			bool addBorrowing(Borrowing b);

			friend ostream &operator<<(ostream &os, const File &f){
				return os;
			}
	};

#endif
