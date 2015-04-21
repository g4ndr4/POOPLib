#pragma once
#ifndef _MemberResult_H_
#define _MemberResult_H_
	#include "Result.h"
	#include "vector"
	#include <iostream>
	#include "File.h"
	class MemberResult : public Result{
	private:
		vector<File *> result;
	public:
		MemberResult();
		~MemberResult();

		void addFile(File *f);

		friend ostream &operator<<(ostream &os, const MemberResult &mr){
			for (auto const it : mr.result){
				os << *it << endl;
			}

			return os;
		}
	};

#endif
