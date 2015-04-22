#pragma once
#ifndef _BorrowBook_H_
	#define _BorrowBook_H_
	#include "ModifyBook.h"
	#include "Book.h"
	class BorrowBook : public ModifyBook{
		Book *book;
		int membership_id;
		Date borrowed_date;
		Date return_date;
	public:
		BorrowBook(Book *b, int mID, Date bd, Date rd, Library *l);
		~BorrowBook();

		void log() override{}
		void undo() override{}

		Result *execute() override;
	};

#endif	