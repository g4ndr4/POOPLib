#pragma once
	#ifndef _FileResult_H_
	#define _FileResult_H_
	#include "Result.h"
	#include "File.h"
	class FileResult : public Result{
	private:
		File *file;
	public:
		FileResult();
		FileResult(File *f);

		File *getFile() const;
		~FileResult();
	};

#endif