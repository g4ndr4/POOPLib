#include "ReturnBook.h"


ReturnBook::ReturnBook(Borrowing *b, Library *l) : ModifyBook(l){
	borrowing = b;
}


ReturnBook::~ReturnBook()
{
}


Result *ReturnBook::execute(){
	book = borrowing->getBook();
	book->setBorrow(nullptr);
	borrowing->returnBook();
	return nullptr;
}