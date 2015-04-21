#pragma once
#ifndef _SearchBooks_H_
#define _SearchBooks_H_
	#include "Library.h"
	#include "SearchingOperation.h"
	class SearchBooks : public SearchingOperation{
	public:
		SearchBooks(Library *l);
		virtual ~SearchBooks();
	};

#endif