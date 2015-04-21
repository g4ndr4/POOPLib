#include "MemberResult.h"


MemberResult::MemberResult() : Result(2){}


MemberResult::~MemberResult(){}

void MemberResult::addFile(File *f){
	result.push_back(f);
}