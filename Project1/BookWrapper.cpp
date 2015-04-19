#include "BookWrapper.h"

//konstruktori i destruktori

BookWrapper::BookWrapper(Book b){
	title = b.getTitle();
	publisherName = b.getPublisherName();
	author = b.getAuthor();
	book_wrap.push_back(&b);
}

BookWrapper::BookWrapper(Book *b){
	title = b->getTitle();
	publisherName = b->getPublisherName();
	author = b->getAuthor();
	book_wrap.push_back(b);
}

BookWrapper::~BookWrapper(){}

//set

//get

string BookWrapper::getTitle() const{
	return title;
}
string BookWrapper::getPublisherName() const{
	return publisherName;
}
vector<string> BookWrapper::getAuthor() const{
	return author;
}

//rad sa book_wrap

void BookWrapper::addBook(Book &b){
	book_wrap.push_back(&b);
}

vector<Book *> BookWrapper::removeBook(string title, int &book_count, vector<Book *> &book_temp){
	for (vector<Book *>::iterator it = book_wrap.begin(); it != book_wrap.end(); ++it){
		if ((*it)->getBorrowing() == nullptr){
			book_temp.push_back(*it);
			cout << "Redni Broj Knjige: " << book_count + 1 << endl;
			cout << *it << endl;
			book_count++;
		}
	}
	return book_temp;
}

Book *BookWrapper::getBook(int index){
	return book_wrap[index];
}

//pretrage

vector<Book*> BookWrapper::searchBorrow(string title, int &book_count, vector<Book *> &book_temp){
	for (vector<Book *>::iterator it = book_wrap.begin(); it != book_wrap.end(); ++it){
		if ((*it)->getBorrowing() == nullptr){
			book_temp.push_back(*it);
			cout << "Redni Broj Knjige: " << book_count + 1 << endl << endl;
			cout << *it << endl;
			book_count++;
		}
	}
	return book_temp;
}

vector<Book*> BookWrapper::searchByTitle(string title, int &book_count, vector<Book *> &book_temp){
	for (vector<Book *>::iterator it = book_wrap.begin(); it != book_wrap.end(); ++it){
		book_temp.push_back(*it);
		cout << "Redni Broj Knjige: " << book_count + 1 << endl << endl;
		cout << *it << endl;
		book_count++;
	}
	return book_temp;
}

vector<Book *> BookWrapper::searchByTitle(string title, int publicationYear, string publisherName, int &book_count, vector<Book *> &book_temp){
	for (vector<Book *>::iterator it = book_wrap.begin(); it != book_wrap.end(); ++it){
		book_temp.push_back(*it);
		cout << "Redni broj knjige: " << book_count + 1 << endl;
		cout << *it << endl;
		book_count++;
	}
	return book_temp;
}

vector<Book *> BookWrapper::searchByBookCondition(string book_condition, int &book_count, vector<Book *> &book_temp){
	for (vector<Book *>::iterator it = book_wrap.begin(); it != book_wrap.end(); ++it){
		if ((*it)->getBookCondition() == book_condition){
			book_temp.push_back(*it);
			cout << "Redni broj knjige: " << book_count + 1 << endl;
			cout << *it << endl;
			book_count++;
		}
	}
	return book_temp;
}

vector<Book *> BookWrapper::searchByReturnDate(Date date, int &book_count, vector<Book *> &book_temp){
	for (vector<Book *>::iterator it = book_wrap.begin(); it != book_wrap.end(); ++it){
		if ((*it)->getBorrowing() != nullptr && (*it)->getBorrowing()->getReturnDate() == date || (*it)->getBorrowing()->getReturnDate() > date){
			book_temp.push_back(*it);
			cout << "Redni broj knjige: " << book_count + 1 << endl;
			cout << *it << endl;
			book_count++;
		}
	}
	return book_temp;
}

//pomocne metode