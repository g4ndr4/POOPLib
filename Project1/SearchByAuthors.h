#pragma once
#ifndef _SearchByAuthors_H_
#define _SearchByAuthors_H_
	#include "SearchBooks.h"
	#include "Library.h"
	class SearchByAuthors : public SearchBooks{
	private:
		string parameter;
	public:
		SearchByAuthors(string argument, Library *l);
		~SearchByAuthors();

		void log() override{}
		void undo() override{}
		Result *execute() override;
	};

#endif