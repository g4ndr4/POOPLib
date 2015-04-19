#pragma once
#ifndef _BookWrapper_H_
	#define _BookWrapper_H_
	#include "Book.h"
	#include "iostream"
	#include "vector"
	#include "string"
	#include "Date.h"
	#include "Borrowing.h"

	class BookWrapper{
	private:
		vector<Book> book_wrap;
		string title;
		string publisherName;
		vector<string> author;
	public:
		
		//konstruktori i destruktori
		
		BookWrapper(Book b);
		~BookWrapper();

		//set

		//get

		string getTitle() const;
		string getPublisherName() const;
		vector<string> getAuthor() const;

		//rad sa BookWrapperom

		void addBook(Book b);
		vector<Book *> removeBook(string title, int &book_count, vector<Book *> &book_temp);
		Book *getBook(int index);
		
		//pretrage

		vector<Book *> searchBorrow(string title, int &book_count, vector<Book *> &book_temp);

		vector<Book *> searchByTitle(string title, int &book_count, vector<Book *> &book_temp);
		vector<Book *> searchByTitle(string title, int publicationYear, string publisherName, int &book_count, vector<Book *> &book_temp);

		vector<Book *> searchByBookCondition(string book_condition, int &book_count, vector<Book *> &book_temp);

		vector<Book *> searchByReturnDate(Date date, int &book_count, vector<Book *> &book_temp);

		//pomocne metode

		friend ostream &operator<<(ostream &os, const BookWrapper &bw){
			os << "-------------------------" << endl;
			os << bw.title << endl;
			os << "-------------------------" << endl;
			int count = 0;
			for (vector<Book>::const_iterator it = bw.book_wrap.begin(); it != bw.book_wrap.end(); ++it){
				os << "Redni Broj Knjige: " << count + 1 << endl;
				os << *it << endl;
				count++;
			}
			os << "-------------------------" << endl;
			return os;
		}
	};

#endif