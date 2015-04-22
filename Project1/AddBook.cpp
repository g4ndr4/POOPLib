#include "AddBook.h"


AddBook::AddBook(Book *b, Library *l) : ModifyBook(l){
	book = b;
}


AddBook::~AddBook(){}

Result *AddBook::execute(){
	library->addBook(*book);
	return nullptr;
}