#include "BookCollection.h"

//konstruktori i destruktori

//set

//get

//rad sa book_collection

void BookCollection::addBook(Book b){
	auto range = book_collection.equal_range(b.getTitle());
	for (auto it = range.first; it != range.second; it++){
		if (it->second.getAuthor() == b.getAuthor() && it->second.getPublisherName() == b.getPublisherName()){
			it->second.addBook(b);
			return;
		}
	}
	book_collection.insert(make_pair(b.getTitle(), b));
	return;
}

void BookCollection::removeBook(string title){
	int book_count = 0;
	vector<Book*> book_temp;
	auto range = book_collection.equal_range(title);
	for (auto it = range.first; it != range.second; it++){
		it->second.removeBook(title, book_count, book_temp);
	}
	int index = 0;
	cout << "Unesite redni broj knjige koju zelite da uklonite ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0 || index > book_count){
		cout << "GRESKA! Uneli ste nedozvoljeni broj!" << endl;
	}
	else book_temp[index - 1]->setBookCondition("Uklonjena");
}

void BookCollection::changeCondition(string title, string book_condition){
	Book *bp = searchByTitle(title);
	bp->setBookCondition(book_condition);
}

//pretrage

Book *BookCollection::searchBorrow(string title){
	int book_count = 0;
	vector<Book*> book_temp;
	auto range = book_collection.equal_range(title);
	for (auto it = range.first; it != range.second; it++){
		it->second.searchBorrow(title, book_count, book_temp);
	}

	int index = 0;
	cout << "Unesite redni broj knjige koju zelite da uzmete ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0 || index > book_count){
		cout << "GRESKA! Uneli ste nedozvoljeni broj!" << endl;
		return nullptr;
	}
	else return book_temp[index - 1];
}

Book *BookCollection::searchByTitle(string title){
	int book_count = 0;
	vector<Book*> book_temp;
	auto range = book_collection.equal_range(title);
	for (auto it = range.first; it != range.second; it++){
		it->second.searchByTitle(title, book_count, book_temp);
	}

	int index = 0;
	cout << "Unesite redni broj knjige koju zelite da uzmete ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0 || index > book_count){
		cout << "GRESKA! Uneli ste nedozvoljeni broj!" << endl;
		return nullptr;
	}
	else return book_temp[index - 1];
}

Book *BookCollection::searchByTitle(string title, int publicationYear, string publisherName){
	int book_count = 0;
	vector<Book*> book_temp;
	auto range = book_collection.equal_range(title);
	for (auto it = range.first; it != range.second; it++){
		if (it->second.getTitle() == title && it->second.getPublisherName() == publisherName){
			it->second.searchByTitle(title, publicationYear, publisherName, book_count, book_temp);
		}
	}

	int index = 0;
	cout << "Unesite redni broj knjige koju zelite da uzmete ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0) return nullptr;
	else return book_temp[index - 1];
}

Book *BookCollection::searchByBookCondition(string book_condition){
	int book_count = 0;
	vector<Book *> book_temp;
	for (unordered_multimap<string, BookWrapper>::iterator it = book_collection.begin(); it != book_collection.end(); ++it){
		it->second.searchByBookCondition(book_condition, book_count, book_temp);
	}

	int index = 0;
	cout << "Unesite redni broj knjige koju zelite da uzmete ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0 || index > book_count){
		cout << "GRESKA! Uneli ste nedozvoljeni broj!" << endl;
		return nullptr;
	}
	else return book_temp[index - 1];
}

Book *BookCollection::searchByReturnDate(ReturnDate date){
	int book_count = 0;
	vector<Book *> book_temp;
	for (unordered_multimap<string, BookWrapper>::iterator it = book_collection.begin(); it != book_collection.end(); ++it){
		it->second.searchByReturnDate(date, book_count, book_temp);
	}

	int index = 0;
	cout << "Unesite redni broj knjige koju zelite da uzmete ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0 || index > book_count){
		cout << "GRESKA! Uneli ste nedozvoljeni broj!" << endl;
		return nullptr;
	}
	else return book_temp[index - 1];
}
//pomocne metode

void BookCollection::history(){
	for (unordered_multimap<string, BookWrapper>::iterator it = book_collection.begin(); it != book_collection.end(); ++it){
		cout << it->second;
		cout << endl << endl;
	}
}