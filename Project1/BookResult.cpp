#include "BookResult.h"

BookResult::BookResult() : Result(1){}

BookResult::BookResult(vector<Book *> *r) : Result(1){
	result = r;
}

BookResult::~BookResult(){}

void BookResult::addBook(Book *b){
	result->push_back(b);
}

Book *BookResult::getBook(int index){
	return result->at(index - 1);
}