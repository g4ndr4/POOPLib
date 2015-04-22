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
			
			File *getFile(int membership_id);

			//operacije sa clanovima
			
			MyMembershipID *newMember(Person *p);

			bool subscribeMember(Person *p);

			Person *unsubscribeMember(int membership_id);

			bool searchForExistingSubscription(long jmbg);
			
			//operacije sa izdavacima
			
			void addPublisher(string name);
			
			//operacije sa knjigama
			
			Library &addBook(Book &b);
			void removeBook(string title);
		//	int borrowBook(MyMembershipID *mID, string title);
			//void returnBook(MyMembershipID *mID, string title);
			//void changeCondition(string title);
			
			//Pretrage
			File *searchFilesByMembershipID(int membership_id);
			vector<Book *> *searchByTitle(string title);
			vector<Book *> *searchByAuthor(string author);
			Book *searchByTitle(string title, int publicationYear, string publisherName);
			
			Book *searchByReturnDate(int day, int month, int year);

			Book *searchByBookCondition(string book_condition);

			vector<File *> *searchFilesByReturnDate(Date current_date, Date borrowing_date);

			vector<File *> *searchFilesByPeriod(Date period_begin, Date period_end);

			//Pomocne metode

			void bookHistory();
	};

#endif
