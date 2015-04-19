#include "Person.h"
#include "Library.h"
#include "Book.h"

PersonalID &Person::getPID(){
	return pID;
}

string Person::getName() const{
	return name;
}

string Person::getSurname() const{
	return surname;
}

MyMembershipID &Person::getMembershipID() const{
	return *mID;
}

bool Person::joinLibrary(Library &lib){
	mID = lib.newMember(this);
	return true;
}

void Person::borrowBook(Library &lib, string title){
	lib.borrowBook(mID, title);
}

Person &Person::returnBook(Library &lib, string title){
	lib.returnBook(mID, title);
	return *this;
}
