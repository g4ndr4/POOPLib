#pragma once
	#ifndef _BorrowingResult_H_
	#define _BorrowingResult_H_
	#include "Result.h"
	#include <vector>
	#include "Borrowing.h"	
	
	class BorrowingResult :public Result{
		private:
			vector<Borrowing *> *result;
		public:
			BorrowingResult();
			BorrowingResult(vector<Borrowing *> *b);
			~BorrowingResult();

			Borrowing *getBorrowing(int index);

			friend ostream &operator<<(ostream &os, const BorrowingResult &br){
				int count = 0;
				for (auto it : *br.result){
					os << "Redni broj pozajmice: " << count + 1 << endl;
					os << *it << endl;
					count++;
				}
				return os;
			}
	};

#endif