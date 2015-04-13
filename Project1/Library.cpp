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

void Library::addBook(string title, vector<string> author, string publisher_name, int publication_year, string genre, string language, int edition, int ISBN_10, int ISBN_13, Position position, string book_condition){
	if (SoP->findPublisher(publisher_name) == true){
		Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, position, book_condition);
		book_collection.addBook(*b);
		return;
	}
	else{
		cout << "Ne postoji izdavac sa tim imenom, da li zelite da dodate izdavaca u listu?" << endl;
		char confirm;
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y'){
			SoP->addPublisher(publisher_name);
			Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, position, book_condition);
			book_collection.addBook(*b);
			return;
		}
	}
	return;
}

void Library::addBook(string title, vector<string> author, string publisher_name, int publication_year, string genre, string language, int edition, int ISBN_10, int ISBN_13, int rID, int cID, int sID, string book_condition){
	if (SoP->findPublisher(publisher_name) == true){
		Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, Position(rID, cID, sID), book_condition);
		book_collection.addBook(*b);
	}
	else{
		cout << "Ne postoji izdavac sa tim imenom, da li zelite da dodate izdavaca u listu?" << endl;
		char confirm;
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y'){
			SoP->addPublisher(publisher_name);
			Book *b = new Book(title, author, publisher_name, publication_year, genre, language, edition, ISBN_10, ISBN_13, Position(rID, cID, sID), book_condition);
			book_collection.addBook(*b);
		}
	}
	return;
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
	//cout << "Unesite dan: "; cin >> day;
	//cout << "Unesite mesec: "; cin >> month;
	//cout << "Unesite godinu: "; cin >> year;
	File *fp = file_storage.searchFilesByMembershipID(mID);
	if (fp){
		Book *bp = book_collection.searchBorrow(title);
		if (bp){
			//Z9 
			int period = 0;
			ReturnDate *rdp;
			period = 20;
			// cout << "Unesite period pozajmice: "; cin >> period;
			if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10){
				if ((day + period) > 31){
					rdp = new ReturnDate((day + period - 31), month + 1, year);
				}
				else rdp = new ReturnDate((day + period), month, year);
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11){
				if ((day + period) > 30){
					rdp = new ReturnDate((day + period - 30), month + 1, year);
				}
				else rdp = new ReturnDate((day + period), month, year);
			}
			else if (month == 12){
				if ((day + period) > 31){
					rdp = new ReturnDate((day + period - 31), 1, year + 1);
				}
				else rdp = new ReturnDate((day + period), month, year);
			}
			else{
				if ((day + period) <= 28){
					rdp = new ReturnDate((day + period), month, year);

				}
				else{
					if (year % 4 == 0 || year % 400 == 0){
						if ((day + period) > 29){
							rdp = new ReturnDate((day + period - 29), month + 1, year);
						}
						else rdp = new ReturnDate((day + period), month, year);
					}
					else{
						if ((day + period) > 28){
							rdp = new ReturnDate((day + period - 28), month + 1, year);
						}
						else rdp = new ReturnDate((day + period), month, year);
					}
				}
			}
			Date date(BorrowedDate(day, month, year), *rdp);
			Borrowing *b = new Borrowing(date, bp);
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
	ReturnDate date(day, month, year);
	return book_collection.searchByReturnDate(date);
}

Borrowing *Library::searchFilesByReturnDate(int cday, int cmonth, int cyear, int bday, int bmonth, int byear){
	ReturnDate current_date(cday, cmonth, cyear);
	BorrowedDate borrowing_date(bday, bmonth, byear);
	return file_storage.searchByReturnDate(current_date, borrowing_date);
}

Borrowing *Library::searchFilesByPeriod(int d1, int m1, int y1, int d2, int m2, int y2){
	BorrowedDate date1(d1, m1, y1);
	BorrowedDate date2(d2, m2, y2);

	return file_storage.searchByPeriod(date1, date2);
}

//pomocne metode

void Library::bookHistory(){
	book_collection.history();
}