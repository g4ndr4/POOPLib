#pragma once
#ifndef _Person_H_
#define _Person_H_
	class Library;
	class Book;
	#include "PersonalID.h"
	#include "MyMembershipID.h"
	#include "iostream"
	#include "cmath"
	#include "string"
	using namespace std;
	class Person{
		private:
			string name;
			string surname;
			PersonalID pID;
			MyMembershipID *mID;
		public:
			Person(string name, string surname, long jmbg) : pID(name, surname, jmbg){
				this->name = name;
				this->surname = surname;
				mID = nullptr;
			};
			
			PersonalID &getPID();
			string getName() const;
			string getSurname() const;
			MyMembershipID &getMembershipID() const;
			
			bool joinLibrary(Library &lib);
			void borrowBook(Library &lib, string title);
			friend ostream &operator<<(ostream &os, const Person &p){
				os << p.pID << endl;
				return os;
			}
	};

#endif

