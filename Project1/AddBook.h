#pragma once
#ifndef _AddBook_H_
	#define _AddBook_H_
	#include "ModifyBook.h"
	class AddBook : public ModifyBook{
		Book *book;
	public:
		AddBook(Book *b, Library *lib);
		~AddBook();

		void log() override{}
		void undo() override{}

		Result *execute() override;
	};
#endif
