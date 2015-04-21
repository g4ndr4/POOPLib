#include "BookResult.h"


BookResult::BookResult(){}


BookResult::~BookResult(){}

void BookResult::addBook(Book *b){
	result.push_back(b);
}