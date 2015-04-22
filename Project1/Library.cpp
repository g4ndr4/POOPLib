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
	if (searchForExistingSubscription(p->getPID().getJmbg())) {
		if (!file_storage.isMember(p->getMembershipID()->getMid())){
			file_storage.setMember(true, p->getMembershipID()->getMid());
			return nullptr;
		}
		return nullptr;
	}	
	File f(p);
	MyMembershipID *mmID = new MyMembershipID(p->getPID());
	file_storage.addFile(f, (*mmID).getMid());
	return mmID;
}

bool Library::subscribeMember(Person *p){
	if (searchForExistingSubscription(p->getPID().getJmbg())) {
		if (!file_storage.isMember(p->getMembershipID()->getMid())){
			file_storage.setMember(true, p->getMembershipID()->getMid());
			return nullptr;
		}
		return nullptr;
	}
	File f(p);
	MyMembershipID *mmID = new MyMembershipID(p->getPID());
	p->setMembershipID(mmID);
	file_storage.addFile(f, (*mmID).getMid());
	return true;
}

Person *Library::unsubscribeMember(int membership_id){
	if (file_storage.isMember(membership_id)){
		file_storage.setMember(false, membership_id);
		return nullptr;
	}
	Person *member = file_storage.unsubscribeMember(membership_id);
	if (member) return member;
	else return nullptr;
}

bool Library::searchForExistingSubscription(long jmbg){
	return file_storage.searchForExistingSubscription(jmbg);
}

//operacije sa izdavacima

void Library::addPublisher(string name){
	SoP->addPublisher(name);
}

//operacije sa knjigama

Library &Library::addBook(Book &b){
	if (SoP->findPublisher(b.getPublisherName()) == true){
		book_collection.addBook(b);
	}
	else{
		cout << "Ne postoji izdavac sa tim imenom, da li zelite da dodate izdavaca u listu?" << endl;
		char confirm;
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y'){
			SoP->addPublisher(b.getPublisherName());
			book_collection.addBook(b);
		}
	}
	return *this;
}

void Library::removeBook(string title){
	book_collection.removeBook(title);
}

/*void Library::changeCondition(string title){
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
}*/

File *Library::searchFilesByMembershipID(int membership_id){
	return file_storage.searchFilesByMembershipID(membership_id);
}
/*
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
			int period = 0;
			Date *rdp;
			cout << "Unesite period pozajmice: "; cin >> period;
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
*/
/*
void Library::returnBook(MyMembershipID *mID, string title){
	File *fp = file_storage.searchFilesByMembershipID(mID);
	if (fp){
		fp->returnBook(title);
	}
}
*/
//pretrage

vector<Book *> *Library::searchByTitle(string title){
	return book_collection.searchByTitle(title);
}

vector<Book *> *Library::searchByAuthor(string author){
	return book_collection.searchByAuthor(author);
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

vector<File *> *Library::searchFilesByReturnDate(Date current_date, Date borrowing_date){
	return file_storage.searchByReturnDate(current_date, borrowing_date);
}

vector<File *> *Library::searchFilesByPeriod(Date period_begin, Date period_end){
	return file_storage.searchByPeriod(period_begin, period_end);
}

//pomocne metode

void Library::bookHistory(){
	book_collection.history();
}