#pragma once
#ifndef _BookCollection_H_
#define _BookCollection_H_
	#include "iostream"
	#include "Book.h"
	#include "BookWrapper.h"
	#include "string"
	#include "unordered_map"
	#include "vector"
	#include "Date.h"
	#include "File.h"
	using namespace std;
	class BookCollection{
		private:
			unordered_multimap<string, BookWrapper> book_collection;
		public:

			//konstruktori i destruktori

			//set

			//get

			//rad sa book_collection

			void addBook(Book b);
			void removeBook(string title);
			void changeCondition(string title, string book_condition);

			//pretrage

			Book *searchBorrow(string title);

			Book *searchByTitle(string title);
			Book *searchByTitle(string title, int publicationYear, string publisherName);

			Book *searchByBookCondition(string book_condition);
			Book *searchByReturnDate(ReturnDate date);

			File *searchFilesByReturnDate(ReturnDate date);
			//pomocne metode

			void history();
	};

#endif