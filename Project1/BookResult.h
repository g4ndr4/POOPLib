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
		virtual ~BookResult();

		void addBook(Book *);

		friend ostream &operator<<(ostream &os, const BookResult &br){
			for (auto it : *br.result){
				os << *it << endl;
			}
			return os;
		}
	};
#endif