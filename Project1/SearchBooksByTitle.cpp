#include "SearchBooksByTitle.h"


SearchBooksByTitle::SearchBooksByTitle(string argument, Library *l) : SearchBooks(l){
	parameter = argument;
}

SearchBooksByTitle::~SearchBooksByTitle(){}

Result *SearchBooksByTitle::execute(){
	return new BookResult(library->searchByTitle(parameter));
}