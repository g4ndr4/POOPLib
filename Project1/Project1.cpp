#include "iostream"
#include "Library.h"
#include "Book.h"
#include "Person.h"
#include "SetOfPublishers.h"
#include "Menu.h"
#include "SearchBooksByTitle.h"
#include "PrintResults.h"
#include "OperationEngine.h"
#include "BookResult.h"
#include "MemberResult.h"
#include "SearchByAuthors.h"
#include "SearchMembersByReturnDate.h"
#include "SearchMembersByPeriod.h"
#include "SubscribeMember.h"
#include "UnsubscribeMember.h"
#include "AddBook.h"
#include "BorrowBook.h"
#include "ReturnBook.h"
#include "SearchMembersByID.h"
#include "Menu.h"

using namespace std;

int main(int argc, char const *argv[]){

	SetOfPublishers *sp = SetOfPublishers::getInstance();
	Library lib(sp);
	OperationEngine operation_engine;
	Person p1("Pera", "Peric", 123);
	Person p2("Milan", "Milic", 456);
	Person p3("Petar", "Petrovic", 789);
	Person p4("Marko", "Markovic", 666);

	SubscribeMember sm1(&p1, &lib);
	SubscribeMember sm2(&p2, &lib);
	SubscribeMember sm3(&p3, &lib);
	SubscribeMember sm4(&p4, &lib);

	operation_engine.submitOperation(&sm1);
	operation_engine.submitOperation(&sm2);
	operation_engine.submitOperation(&sm3);
	operation_engine.submitOperation(&sm4);


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
	Book b1("Naslov1", autor1, "Izdavac1", 1999, "zanr", "jezik", 1, "ISBN10", "ISBN13", 1, 1, 1);
	Book b2("Naslov2", autor1, "Izdavac2", 2000, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 2, "Potrebno_Zameniti");
	Book b3("Naslov2", autor2, "Izdavac2", 2002, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 3, "Nova");
	Book b4("Naslov2", autor1, "Izdavac2", 2001, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 4, "Potrebno_Zameniti");
	Book b5("Naslov2", autor1, "Izdavac2", 2001, "zanr", "jezik", 1, "ISBN10", "ISBN13", 2, 2, 4, "Potrebno_Zameniti");
	Book b6("Naslov3", autor3, "Izdavac1", 200, "zanr", "jezik", 1, "ISBN10", "ISBN13", 4, 4, 4);
	AddBook ab(&b1, &lib);
	operation_engine.submitOperation(&ab);
	lib.addBook(b2).addBook(b3).addBook(b4).addBook(b5).addBook(b6);
	Book *bp1 = &b1;
	Book *bp2 = &b2;
	Book *bp3 = &b3;
	Book *bp4 = &b4;
	Book *bp5 = &b5;
	Book *bp6 = &b6;

	Menu menu(&lib);
	bool terminate = false;
	while (!terminate){
		terminate = menu.select();
	}

	SearchBooksByTitle sbt("Naslov1", &lib);
	Result *r = operation_engine.submitOperation(&sbt);
	BookResult *br = dynamic_cast<BookResult *>(r);
	Book * knjiska = br->getBook(0);
	BorrowBook bb(knjiska, 1, Date(1, 2, 3), Date(2, 3, 4), &lib);
	operation_engine.submitOperation(&bb);
	SearchBooksByTitle sbt1("Naslov3", &lib);
	r = operation_engine.submitOperation(&sbt1);
	br = dynamic_cast<BookResult *>(r);
	knjiska = br->getBook(0);
	BorrowBook bb1(knjiska, 1, Date(1, 2, 3), Date(2, 3, 4), &lib);
	operation_engine.submitOperation(&bb1);
	SearchMembersByID smbid(1, &lib);
	r = operation_engine.submitOperation(&smbid);
	MemberResult *fajliska = dynamic_cast<MemberResult *>(r);
	File *f = fajliska->getFile(0);
	Borrowing *b = f->getBorrowing(0);
	ReturnBook rb1(b, &lib);
	ReturnBook rb2(f->getBorrowing(1), &lib);
	operation_engine.submitOperation(&rb1);
	operation_engine.submitOperation(&rb2);
	
	string s;
	//cin >> s;

	
	//PrintResults pr(r, &lib);
	//operation_engine.submitOperation(&pr);
	//cin >> s;
	//SearchByAuthors sba(s, &lib);
	//Result *r = operation_engine.submitOperation(&sba);
	//PrintResults pr1(r, &lib);
	//operation_engine.submitOperation(&pr1);
/*	Person p5("Djordano", "Bruno", 1244);
	SubscribeMember sm(&p5, &lib);
	operation_engine.submitOperation(&sm);
	operation_engine.undo(&sm);
	UnsubscribeMember um(5, &lib);
	operation_engine.submitOperation(&um);
	operation_engine.undo(&um);
	UnsubscribeMember um1(5, &lib);
	operation_engine.submitOperation(&um1);
	operation_engine.undo(&um1);
	UnsubscribeMember um2(5, &lib);
	operation_engine.submitOperation(&um2);
	
	p5.borrowBook(lib, "Naslov2");
	p2.borrowBook(lib, "Naslov2");
	SearchMembersByPeriod sbpr(1, 04, 2015, 30, 04, 2015, &lib);
	Result *r = operation_engine.submitOperation(&sbpr);
	PrintResults pr1(r, &lib);
	operation_engine.submitOperation(&pr1);
	*/
//	lib.addBook("Zbirka zadataka iz matematike", autor4, "Zavod za udzbenike", 2011, "zanr", "jezik", 1, "ISBN10", "ISBN13", 10, 11, 3, "Potrebno_Zameniti");
	//lib.addBook("Zbirka zadataka iz matematike", autor5, "Krug", 2011, "zanr", "jezik", 1, "ISBN10", "ISBN13", 10, 11, 3, "Potrebno_Zameniti");
	lib.bookHistory();
	
	//p1.returnBook(lib, "Naslov2");
	//p2.borrowBook(lib, "Naslov2");
	//p3.borrowBook(lib, "Naslov3");
	//lib.changeCondition("Naslov1");
	//lib.searchFilesByReturnDate(17, 3, 2015, 1, 1, 2015);
	lib.searchByBookCondition("Malo_Ostecena");

	lib.bookHistory();

	lib.removeBook("Naslov2");

	lib.bookHistory();
	int i;
	cin >> i;
	return 0;
}

