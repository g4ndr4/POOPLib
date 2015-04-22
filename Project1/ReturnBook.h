#pragma once
#ifndef _ReturnBook_H_
	#define _ReturnBook_H_
	#include "ModifyBook.h"
	class ReturnBook : public ModifyBook{
	private:
		Borrowing *borrowing;
		Book *book;
	public:
		ReturnBook(Borrowing *b, Library *l);
		~ReturnBook();

		void log() override{}

		void undo() override{}

		Result *execute() override;
	};

#endif