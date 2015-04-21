#pragma once
#ifndef _Library_H_
#define _Library_H_
	#include "iostream"
	#include <regex>
	#include "Result.h"
	#include "BookResult.h"
	#include "MemberResult.h"
	#include "FileStorage.h"
	class Person;
	#include "MyMembershipID.h"
	#include "BookCollection.h"
	#include "SetOfPublishers.h"
	using namespace std;

	class Library{
		private:
			FileStorage file_storage;
			BookCollection book_collection;
			SetOfPublishers *SoP;
			int borrowing_limit = 0;
		public:
			
			//konstruktori i destruktori
			
			Library(SetOfPublishers *sp);

			//set

			void setBorrowingLimmit(int n);

			//get
			
			//operacije sa clanovima
			
			MyMembershipID *newMember(Person *p);
			
			//operacije sa izdavacima
			
			void addPublisher(string name);
			
			//operacije sa knjigama
			
			Library &addBook(Book &b);
			void removeBook(string title);
			int borrowBook(MyMembershipID *mID, string title);
			void returnBook(MyMembershipID *mID, string title);
			//void changeCondition(string title);
			
			//Pretrage
			
			vector<Book *> *searchByTitle(string title);
			vector<Book *> *searchByAuthor(string author);
			Book *searchByTitle(string title, int publicationYear, string publisherName);
			
			Book *searchByReturnDate(int day, int month, int year);

			Book *searchByBookCondition(string book_condition);

			Borrowing *searchFilesByReturnDate(int cday, int cmonth, int cyear, int bday, int bmonth, int byear);

			Borrowing *searchFilesByPeriod(int d1, int m1, int y1, int d2, int m2, int y2);

			//Pomocne metode

			void bookHistory();
	};

#endif
