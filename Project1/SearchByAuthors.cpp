#include "SearchByAuthors.h"


SearchByAuthors::SearchByAuthors(string argument, Library *l) : SearchBooks(l){
	parameter = argument;
}


SearchByAuthors::~SearchByAuthors(){}

Result *SearchByAuthors::execute(){
	return new BookResult(library->searchByAuthor(parameter));
}