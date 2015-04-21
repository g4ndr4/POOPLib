#pragma once
#ifndef _Menu_H_
#define _Menu_H_
	#include <iostream>	
	#include <string.h>
	#include "Library.h"
	using namespace std;

	class Menu{
	private:
		Library *lib;
	public:
		Menu(Library &l);
		~Menu();
		
		bool select();



	};

#endif