#include "Result.h"


Result::Result(int rt){
	result_type = rt;
}

Result::~Result(){}

int Result::getCode() const{
	return result_type;
}