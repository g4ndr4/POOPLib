#include "MemberResult.h"

MemberResult::MemberResult() : Result(2){}

MemberResult::MemberResult(vector<File *> *r) : Result(2){
	result = r;
}


MemberResult::~MemberResult(){}

void MemberResult::addFile(File *f){
	result->push_back(f);
}