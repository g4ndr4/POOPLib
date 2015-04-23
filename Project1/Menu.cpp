#include "Menu.h"


Menu::Menu(Library *l){
	library = l;
}


Menu::~Menu(){}


bool Menu::select(){
	cout << "Meni" << endl;
	cout << "1. Uclanjivanje osobe;" << endl;
	cout << "2. Isclanjivanje clana;" << endl;
	cout << "3. Pozajmljivanje knjige;" << endl;
	cout << "4. Vracanje knjige;" << endl;
	cout << "0. Kraj rada;" << endl;
	int selector = 0;
	cin >> selector;
	if (selector == 1){
		string name;
		string surname;
		long jmbg;
		cout << "Ime: "; cin >> name; cout << endl;
		cout << "Prezime: "; cin >> surname; cout << endl;
		cout << "JMBG: "; cin >> jmbg; cout << endl;
		Person *p = new Person(name, surname, jmbg);
		SubscribeMember subscribe_member(p, library);
		operation_engine.submitOperation(&subscribe_member);
		return false;
	}
	else if (selector == 2){
		int membership_id;
		cout << "Unesite broj clanske karte: "; cin >> membership_id; cout << endl;
		UnsubscribeMember unsubscribe_member(membership_id, library);
		operation_engine.submitOperation(&unsubscribe_member);
		return false;
	}
	else if (selector == 3){
		string title;
		int index;
		int membership_id;
		int borrowing_day, borrowing_month, borrowing_year;
		int return_day, return_month, return_year;
		cout << "Unesite broj clanske karte: "; cin >> membership_id; cout << endl;
		cout << "Unesite datum pozajmice: "; cin >> borrowing_day; cin >> borrowing_month; cin >> borrowing_year; cout << endl;
		Date borrowed_date(borrowing_day, borrowing_month, borrowing_year);
		cout << "Unesite datum vracanja: "; cin >> return_day; cin >> return_month; cin >> return_year; cout << endl;
		Date return_date(return_day, return_month, return_year);
		cout << "Unesite naziv knjige: "; cin >> title; cout << endl;
		SearchBooksByTitle search_books_by_title(title, library);
		BookResult *result = dynamic_cast<BookResult *>(operation_engine.submitOperation(&search_books_by_title));
		cout << *result << endl;
		cout << "Izaberite jednu od pronadjenih knjiga: "; cin >> index; cout << endl;
		Book *book = result->getBook(index);
		BorrowBook borrow_book(book, membership_id, borrowed_date, return_date, library);
		operation_engine.submitOperation(&borrow_book);
		return false;
	}
	else if (selector == 4){
		int membership_id;
		int index;
		cout << "Unesite broj clanske karte: "; cin >> membership_id;
		SearchBorrowings search_borrowings(membership_id, library);
		BorrowingResult *result = dynamic_cast<BorrowingResult *>(operation_engine.submitOperation(&search_borrowings));
		cout << *result << endl;
		cout << "Izaberite jednu od pronadjenih pozajmica: "; cin >> index; cout << endl;
		Borrowing *borrowing = result->getBorrowing(index);
		ReturnBook return_book(borrowing, library);
		operation_engine.submitOperation(&return_book);
	}
	else if (selector == 0){
		selector = 0;
		return true;
	}
	else cout << "*** Nepostojeca opcija!" << endl << endl;
	return false;
}