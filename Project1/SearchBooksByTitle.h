#pragma once
#ifndef _SearchBooksByTitle_H_
#define _SearchBooksByTitle_H_
	#include <iostream>
	#include <string>
	#include "SearchBooks.h"
	#include "Library.h"
	class SearchBooksByTitle : public SearchBooks{
	private:
		string parameter;
	public:
		SearchBooksByTitle(string argument, Library *l);
		~SearchBooksByTitle();

		void log() override{};

		void undo() override{};

		Result *execute() override;
	};

#endif