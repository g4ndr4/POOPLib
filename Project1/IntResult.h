#pragma once
#ifndef _IntResult_H_
	#define _IntResult_H_
	#include "Result.h"
	#include <iostream>
	using namespace std;
	class IntResult : public Result{
	private:
		int result;
	public:
		IntResult();
		IntResult(int r);
		~IntResult();

		int getResult() const;

		friend ostream &operator<<(ostream &os, const IntResult &ir){
			os << result;
			return os;
		}
	};

#endif
