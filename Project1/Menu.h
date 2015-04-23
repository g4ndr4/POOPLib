#pragma once
#ifndef _Menu_H_
#define _Menu_H_
	#include <iostream>	
	#include <string.h>
	#include "Library.h"
	#include "OperationEngine.h"
	#include "SubscribeMember.h"
	#include "UnsubscribeMember.h"
	#include "SearchBooksByTitle.h"
	#include "BorrowBook.h"
	#include "ReturnBook.h"
	#include "SearchMembersByID.h"
	#include "SearchBorrowings.h"
	#include "FileResult.h"
	using namespace std;

	class Menu{
	private:
		OperationEngine operation_engine;
		Library *library;
	public:
		Menu(Library *l);
		~Menu();
		
		bool select();



	};

#endif