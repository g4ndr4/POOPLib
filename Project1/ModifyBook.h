#pragma once
#ifndef _ModifyBook_H_
	#define _ModifyBook_H_
	#include "ModifyingOperation.h"
	#include "Library.h"
	class ModifyBook : public ModifyingOperation{
	public:
		ModifyBook(Library *l);
		virtual ~ModifyBook();
	};
#endif