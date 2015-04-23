#pragma once
#ifndef _BookResult_H_
#define _BookResult_H_
	#include "Result.h"
	#include "vector"
	#include <iostream>
	#include "Book.h"
	using namespace std;
	class BookResult : public Result{
	private: 
		vector<Book *> *result;
	public:
		BookResult();
		BookResult(vector<Book *> *r);
		~BookResult();

		void addBook(Book *);

		Book *getBook(int index);

		friend ostream &operator<<(ostream &os, const BookResult &br){
			int count = 0;
			for (auto it : *br.result){
				os << "Redni broj knjige: " << count + 1 << endl;
				os << *(it) << endl;
				count++;
			}
			return os;
		}
	};
#endif