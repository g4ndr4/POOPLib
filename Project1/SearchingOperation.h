#pragma once
#ifndef _SearchingOperation_H_
#define _SearchingOperation_H_
	#include "Library.h"
	#include "Operation.h"
	class SearchingOperation : public Operation{
	public:
		SearchingOperation(Library *l);
		virtual ~SearchingOperation();
	};

#endif