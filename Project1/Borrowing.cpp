#include "Borrowing.h"

//konstruktori i destruktori

Borrowing::Borrowing(Date borrowed_date, Date return_date, Book *b) : borrowedDate(borrowed_date), returnDate(return_date){
	book = b;
}

//set

//get

Book *Borrowing::getBook() const{
	return book;
}

Date Borrowing::getBorrowedDate() const{
	return borrowedDate;
}

Date Borrowing::getReturnDate() const{
	return returnDate;
}

//pomocne metode

void Borrowing::returnBook(){
	book = nullptr;
}