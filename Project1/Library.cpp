#include "Library.h"

//konstruktori i destruktori

Library::Library(SetOfPublishers *sp){
	SoP = sp;
}

//set

void Library::setBorrowingLimmit(int n){
	borrowing_limit = n;
}

//get

//operacije sa clanovima

MyMembershipID *Library::newMember(Person *p){
	if (&(p->getMembershipID()) != nullptr){
		cout << "Greska! Osoba je vec clan biblioteke!" << endl;
		return nullptr;
	}
	File f(p);
	MyMembershipID *mmID = new MyMembershipID(p->getPID());
	file_storage.addFile(f, (*mmID).getMid());
	return mmID;
}

//operacije sa izdavacima

void Library::addPublisher(string name){
	SoP->addPublisher(name);
}

//operacije sa knjigama

Library &Library::addBook(string title, vector<string> author, string publisher_name, int publication_year, string genre, string language, int edition, string ISBN_10, string ISBN_13, Position position, string book_condition){
	if (SoP->findPublisher(publisher_name) == true){
		Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, position, book_condition);
		book_collection.addBook(*b);
		return *this;
	}
	else{
		cout << "Ne postoji izdavac sa tim imenom, da li zelite da dodate izdavaca u listu?" << endl;
		char confirm;
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y'){
			SoP->addPublisher(publisher_name);
			Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, position, book_condition);
			book_collection.addBook(*b);
			return *this;
		}
	}
	return *this;
}

Library &Library::addBook(string title, vector<string> author, string publisher_name, int publication_year, string genre, string language, int edition, string ISBN_10, string ISBN_13, int rID, int cID, int sID, string book_condition){
	if (SoP->findPublisher(publisher_name) == true){
		Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, Position(rID, cID, sID), book_condition);
		book_collection.addBook(*b);
		return *this;
	}
	else{
		cout << "Ne postoji izdavac sa tim imenom, da li zelite da dodate izdavaca u listu?" << endl;
		char confirm;
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y'){
			SoP->addPublisher(publisher_name);
			Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, Position(rID, cID, sID), book_condition);
			book_collection.addBook(*b);
			return *this;
		}
	}
	return *this;
}

void Library::removeBook(string title){
	book_collection.removeBook(title);
}

void Library::changeCondition(string title){
	string book_condition;
	cout << "Unesite novo stanje: "; cin >> book_condition;
	if (book_condition == "Nova") book_collection.changeCondition(title, "Nova");
	else if (book_condition == "Malo_Ostecena") book_collection.changeCondition(title, "Malo_Ostecena");
	else if (book_condition == "Veoma_Ostecena") book_collection.changeCondition(title, "Veoma_Ostecena");
	else if (book_condition == "Neophodna_Zamena") book_collection.changeCondition(title, "Potrebno_Zameniti");
	else if (book_condition == "Uklonjena") book_collection.changeCondition(title, "Uklonjena");
	else {
		cout << "GRESKA! Uneli ste nepostojece stanje!" << endl;
		return;
	}
}


//Z8
int Library::borrowBook(MyMembershipID *mID, string title){
	int day, month, year;
	
	cout << "Unesite dan: "; cin >> day;
	cout << "Unesite mesec: "; cin >> month;
	cout << "Unesite godinu: "; cin >> year;
	Date current_date(day, month, year);

	File *fp = file_storage.searchFilesByMembershipID(mID);
	if (fp){
		Book *bp = book_collection.searchBorrow(title);
		if (bp){
			//Z9 
			int period = 0;
			Date *rdp;
			period = 20;
			// cout << "Unesite period pozajmice: "; cin >> period;
			rdp = current_date.calculateReturnDate(period);
			Date return_date(*rdp);
			Borrowing *b = new Borrowing(current_date, return_date, bp);
			bp->setBorrow(b);
			fp->addBorrowing(*b);
			return 1;
		}
		else return -2;
	}
	else return -1;

}

//pretrage

Book *Library::searchByTitle(string title){
	return book_collection.searchByTitle(title);
}

Book *Library::searchByTitle(string title, int publicationYear, string publisherName){
	return book_collection.searchByTitle(title, publicationYear, publisherName);
}

Book *Library::searchByBookCondition(string book_condition){
	if (book_condition == "Nova") return book_collection.searchByBookCondition("Nova");
	else if (book_condition == "Malo_Ostecena") return book_collection.searchByBookCondition("Malo_Ostecena");
	else if (book_condition == "Veoma_Ostecena") return book_collection.searchByBookCondition("Veoma_Ostecena");
	else if (book_condition == "Neophodna_Zamena") return book_collection.searchByBookCondition("Neophodna_Zamena");
	else if (book_condition == "Uklonjena") return book_collection.searchByBookCondition("Uklonjena");
	else{
		cout << "GRESKA! Uneli ste nepostojece stanje!" << endl;
		return nullptr;
	}
}

Book *Library::searchByReturnDate(int day, int month, int year){
	Date date(day, month, year);
	return book_collection.searchByReturnDate(date);
}

Borrowing *Library::searchFilesByReturnDate(int cday, int cmonth, int cyear, int bday, int bmonth, int byear){
	Date current_date(cday, cmonth, cyear);
	Date borrowing_date(bday, bmonth, byear);
	return file_storage.searchByReturnDate(current_date, borrowing_date);
}

Borrowing *Library::searchFilesByPeriod(int d1, int m1, int y1, int d2, int m2, int y2){
	Date date1(d1, m1, y1);
	Date date2(d2, m2, y2);

	return file_storage.searchByPeriod(date1, date2);
}

//pomocne metode

void Library::bookHistory(){
	book_collection.history();
}