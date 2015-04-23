#include "FileResult.h"


FileResult::FileResult() : Result(4){}

FileResult::FileResult(File *f) : Result(4){
	file = f;
}

File *FileResult::getFile() const{
	return file;
}

FileResult::~FileResult()
{
}
