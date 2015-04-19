#pragma once
#ifndef _Book_H_
#define _Book_H_
#include "iostream"
#include "Position.h"
#include "string"
#include "vector"
class Borrowing;
using namespace std;

class Book{
private:
	enum BookCondition{ Nova, Malo_Ostecena, Veoma_Ostecena, Potrebno_Zameniti, Uklonjena };
	string title;
	vector<string> author;
	string publisherName;
	int publicationYear;
	string genre;
	string language;
	int edition;
	string ISBN10;
	string ISBN13;
	Position position;
	BookCondition bookCondition;
	Borrowing *borrowing;
public:

	//konstruktori i destruktori

	Book(string t, vector<string> a, string publisher_name, int publication_year, string g, string l, int e, string ISBN_10, string ISBN_13, Position pos, string book_condition = "Nova");
	Book(string t, vector<string> a, string publisher_name, int publication_year, string g, string l, int e, string ISBN_10, string ISBN_13, int rID, int cID, int sID, string book_condition = "Nova");

	//set

	void setBorrow(Borrowing *bo);
	void setBookCondition(string book_condition);

	//get

	string getTitle() const;
	vector<string> getAuthor() const;
	string getPublisherName() const;
	int getPublicationYear() const;
	string getGenre() const;
	string getLanguage() const;
	int getEdition() const;
	string getISBN10() const;
	string getISBN13() const;
	Position getPosition() const;
	string getBookCondition() const;
	Borrowing *getBorrowing() const;

	//pretrage

	//pomocne metode

	ostream &printAuthors(ostream &os) const{
		for (vector<string>::const_iterator it = author.begin(); it != author.end(); ++it){
			os << *it << " ";
		}
		return os;
	}

	friend ostream &operator<<(ostream &os, const Book &b){
		os << "=========================" << endl;
		os << "Naslov knjige: " << b.getTitle() << endl;
		os << "Autor(i): ";
		b.printAuthors(os);
		os << endl;
		os << "Ime izdavaca: " << b.publisherName << endl;
		os << "Godina izdanja: " << b.publicationYear << endl;
		os << "Zanr: " << b.genre << endl;
		os << "Jezik: " << b.language << endl;
		os << "Izdanje: " << b.edition << endl;
		os << "ISBN 10: " << b.ISBN10 << endl;
		os << "ISBN 13: " << b.ISBN13 << endl;
		os << b.position << endl;
		os << "Stanje knjige: ";
		switch (b.bookCondition){
		case Nova:
			os << "Nova" << endl;
			break;
		case Malo_Ostecena:
			os << "Malo Ostecena" << endl;
			break;
		case Veoma_Ostecena:
			os << "Veoma Ostecena" << endl;
			break;
		case Potrebno_Zameniti:
			os << "Potrebno Zameniti" << endl;
			break;
		case Uklonjena:
			os << "Uklonjena" << endl;
			break;
		}
		os << "Na Pozajmici: ";
		if (b.getBorrowing() == nullptr){
			os << "NE" << endl;
		}
		else os << "DA" << endl;
		os << "=========================" << endl;

		return os;
	}
};

#endif
