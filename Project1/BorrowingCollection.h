#pragma once
#ifndef _BorrowingCollection_H_
	#define _BorrowingCollection_H_
	#include "vector"
	#include "iostream"
	#include "Borrowing.h"
	using namespace std;

	class BorrowingCollection{
	private:
		vector<Borrowing> borrowing_collection;
	public:
		
		//konstruktori i destruktori
		
		bool addBorrowing(Borrowing b);
		vector<Borrowing> *getBorrowing(){
			return &borrowing_collection;
		}

		bool hasActiveBorrowings() const;

		void returnBook(string title, int &borrowing_count, vector<Borrowing *> &borrowing_temp);

		bool searchByReturnDate(Date current_date, Date borrowing_date);

		bool searchByPeriod(Date period_begin, Date period_end);
	};

#endif