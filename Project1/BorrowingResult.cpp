#include "BorrowingResult.h"


BorrowingResult::BorrowingResult() : Result(5){}

BorrowingResult::BorrowingResult(vector<Borrowing *> *b) : Result(5){
	result = b;
}

BorrowingResult::~BorrowingResult(){}

Borrowing *BorrowingResult::getBorrowing(int index){
	return result->at(index - 1);
}