#include "Book.h"
#include "Borrowing.h"

//konstruktori i destruktori

Book::Book(string t, vector<string> a, string publisher_name, int publication_year, string g, string l, int e, string ISBN_10, string ISBN_13, Position pos, string book_condition) : position(pos){
	title = t;
	author = a;
	publisherName = publisher_name;
	publicationYear = publication_year;
	genre = g;
	language = l;
	edition = e;
	ISBN10 = ISBN_10;
	ISBN13 = ISBN_13;
	borrowing = nullptr;
	if (book_condition == "Nova"){
		bookCondition = Nova;
	}
	else if (book_condition == "Malo_Ostecena"){
		bookCondition = Malo_Ostecena;
	}
	else if (book_condition == "Veoma_Ostecena"){
		bookCondition = Veoma_Ostecena;
	}
	else if (book_condition == "Potrebno_Zameniti"){
		bookCondition = Potrebno_Zameniti;
	}
	else if (book_condition == "Uklonjena"){
		bookCondition = Uklonjena;
	}
	else bookCondition = Nova;
}

Book::Book(string t, vector<string> a, string publisher_name, int publication_year, string g, string l, int e, string ISBN_10, string ISBN_13, int rID, int cID, int sID, string book_condition) : position(rID, cID, sID){
	title = t;
	author = a;
	publisherName = publisher_name;
	publicationYear = publication_year;
	genre = g;
	language = l;
	edition = e;
	ISBN10 = ISBN_10;
	ISBN13 = ISBN_13;
	borrowing = nullptr;
	if (book_condition == "Nova"){
		bookCondition = Nova;
	}
	else if (book_condition == "Malo_Ostecena"){
		bookCondition = Malo_Ostecena;
	}
	else if (book_condition == "Veoma_Ostecena"){
		bookCondition = Veoma_Ostecena;
	}
	else if (book_condition == "Potrebno_Zameniti"){
		bookCondition = Potrebno_Zameniti;
	}
	else if (book_condition == "Uklonjena"){
		bookCondition = Uklonjena;
	}
	else bookCondition = Nova;
}

//set

void Book::setBorrow(Borrowing *bo){
	borrowing = bo;
}

void Book::setBookCondition(string book_condition){
	if (book_condition == "Nova"){
		bookCondition = Nova;
	}
	else if (book_condition == "Malo_Ostecena"){
		bookCondition = Malo_Ostecena;
	}
	else if (book_condition == "Veoma_Ostecena"){
		bookCondition = Veoma_Ostecena;
	}
	else if (book_condition == "Potrebno_Zameniti"){
		bookCondition = Potrebno_Zameniti;
	}
	else if (book_condition == "Uklonjena"){
		bookCondition = Uklonjena;
	}
	else bookCondition = Nova;
}

//get

string Book::getTitle() const{
	return title;
}

vector<string> Book::getAuthor() const{
	return author;
}

string Book::getPublisherName() const{
	return publisherName;
}

int Book::getPublicationYear() const{
	return publicationYear;
}

string Book::getGenre() const{
	return genre;
}

string Book::getLanguage() const{
	return language;
}

int Book::getEdition() const{
	return edition;
}

string Book::getISBN10() const{
	return ISBN10;
}

string Book::getISBN13() const{
	return ISBN13;
}

Position Book::getPosition() const{
	return position;
}

string Book::getBookCondition() const{
	switch (bookCondition){
	case 0:
		return "Nova";
		break;
	case 1:
		return "Malo_Ostecena";
		break;
	case 2:
		return "Veoma_Ostecena";
		break;
	case 3:
		return "Potrebno_Zameniti";
		break;
	case 4:
		return "Uklonjena";
		break;
	}
}

Borrowing *Book::getBorrowing() const{
	return borrowing;
}


//pretrage

//pomocne metode