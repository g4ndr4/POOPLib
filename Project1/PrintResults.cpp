#include "PrintResults.h"


PrintResults::PrintResults(Result *r, Library *l) : ViewingOperation(l){
	result = r;
}


PrintResults::~PrintResults(){}

Result *PrintResults::execute(){
	if (result->getCode() == 1){
		cout << *dynamic_cast<BookResult *>(result) << endl;
	}
	else cout << *dynamic_cast<MemberResult *>(result) << endl;
	return nullptr;
}
