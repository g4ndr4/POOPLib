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

		vector<Borrowing *> searchByReturnDate(ReturnDate current_date, BorrowedDate borrowing_date, int &borrowing_count, vector<Borrowing *> &borrowing_temp);

		vector<Borrowing *> searchByPeriod(BorrowedDate date1, BorrowedDate date2, int &borrowing_count, vector<Borrowing *> &borrowing_temp);
		//Z6.
	};

#endif