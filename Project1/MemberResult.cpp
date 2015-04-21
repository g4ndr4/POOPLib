#include "MemberResult.h"


MemberResult::MemberResult(){}


MemberResult::~MemberResult(){}

void MemberResult::addFile(File *f){
	result.push_back(f);
}