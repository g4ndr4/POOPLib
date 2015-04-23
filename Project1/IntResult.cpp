#include "IntResult.h"


IntResult::IntResult(int r){
	result = r;
}


IntResult::~IntResult(){}

int IntResult::getResult() const{
	return result;
}