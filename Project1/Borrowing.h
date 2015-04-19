#pragma once
#ifndef _Borrowing_H_
	#define _Borrowing_H_
	#include "iostream"
	#include "Date.h"
	#include "Book.h"
	using namespace std;
	
	class Borrowing{
	private:
		Date borrowedDate;
		Date returnDate;
		Book *book;
	public:
		
		//konstruktori i destruktori
		
		Borrowing(Date borrowed_date, Date return_date, Book *b);
		
		//set

		//get

		Book *getBook() const;
		Date getBorrowedDate() const;
		Date getReturnDate() const;

		//pomocne metode

		void returnBook();

		friend ostream &operator<<(ostream &os, const Borrowing &b){
			os << *(b.book) << endl;
			os << "Datum pozajmice: " << b.borrowedDate << endl;
			os << "Datum povracaja: " << b.returnDate << endl;
			return os;
		}
	};


#endif