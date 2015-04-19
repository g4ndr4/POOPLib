#include "iostream"
#include "Library.h"
#include "Book.h"
#include "Person.h"
#include "SetOfPublishers.h"

using namespace std;

int main(int argc, char const *argv[]){

	SetOfPublishers *sp = SetOfPublishers::getInstance();
	Library lib(sp);

	Person p1("Pera", "Peric", 123);
	Person p2("Milan", "Milic", 456);
	Person p3("Petar", "Petrovic", 789);
	Person p4("Marko", "Markovic", 666);

	p1.joinLibrary(lib);
	p2.joinLibrary(lib);
	p3.joinLibrary(lib);
	p4.joinLibrary(lib);

	Position posi1(1, 1, 1), posi2(2, 2, 2);
	vector<string> autor1;
	vector<string> autor2;
	vector<string> autor3;
	autor1.push_back("Pera");
	autor1.push_back("Mika");
	autor2.push_back("Laza");
	autor3.push_back("Pera");
	autor3.push_back("Mika");
	lib.addBook("Naslov1", autor1, "Izdavac1", 1999, "zanr", "jezik", 1, "ISBN10", "ISBN13", 1, 1, 1).addBook("Naslov2", autor1, "Izdavac2", 2000, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 2, "Potrebno_Zameniti").addBook("Naslov2", autor2, "Izdavac2", 2002, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 3, "Nova").addBook("Naslov2", autor1, "Izdavac2", 2001, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 4, "Potrebno_Zameniti").addBook("Naslov2", autor1, "Izdavac2", 2001, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 4, "Potrebno_Zameniti").addBook("Naslov3", autor3, "Izdavac1", 200, "zanr", "jezik", 1, "ISBN10", "ISBN13", 4, 4, 4);

	vector<string> autor4;
	vector<string> autor5;
	autor4.push_back("Vene T. Bogoslavov");
	autor5.push_back("Srdjan Ognjanovic");
	lib.addBook("Zbirka zadataka iz matematike", autor4, "Zavod za udzbenike", 2011, "zanr", "jezik", 1, "ISBN10", "ISBN13", 10, 11, 3, "Potrebno_Zameniti");
	lib.addBook("Zbirka zadataka iz matematike", autor5, "Krug", 2011, "zanr", "jezik", 1, "ISBN10", "ISBN13", 10, 11, 3, "Potrebno_Zameniti");
	lib.bookHistory();
	p1.borrowBook(lib, "Naslov2");
	p1.returnBook(lib, "Naslov2");
	p2.borrowBook(lib, "Naslov2");
	p3.borrowBook(lib, "Naslov3");
	lib.changeCondition("Naslov1");
	lib.searchFilesByReturnDate(17, 3, 2015, 1, 1, 2015);
	lib.searchByBookCondition("Malo_Ostecena");

	lib.bookHistory();

	lib.removeBook("Naslov2");

	lib.bookHistory();
	int i;
	cin >> i;

	return 0;
}

