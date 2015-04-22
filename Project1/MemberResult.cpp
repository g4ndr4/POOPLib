#include "MemberResult.h"

MemberResult::MemberResult() : Result(2){}

MemberResult::MemberResult(vector<File *> *r) : Result(2){
	result = r;
}

MemberResult::MemberResult(vector<File *> r) : result(&r), Result(2){
}

File *MemberResult::getFile(int index){
	return result->at(index);
}

MemberResult::~MemberResult(){}

void MemberResult::addFile(File *f){
	result->push_back(f);
}