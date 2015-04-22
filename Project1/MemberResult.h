#pragma once
#ifndef _MemberResult_H_
#define _MemberResult_H_
	#include "Result.h"
	#include "vector"
	#include <iostream>
	#include "File.h"
	using namespace std;
	class MemberResult : public Result{
	private:
		vector<File *> *result;
	public:
		MemberResult();
		MemberResult(vector<File *> r);
		MemberResult(vector<File *> *r);
		virtual ~MemberResult();

		void addFile(File *f);
		File *getFile(int index);

		friend ostream &operator<<(ostream &os, const MemberResult &mr){
			for (auto it : *mr.result){
				os << *it << endl;
			}
			return os;
		}
	};

#endif
