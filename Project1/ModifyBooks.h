#pragma once
#ifndef _ModifyBooks_H_
	#define _ModifyBooks_H_
	#include "ModifyingOperation.h"
	#include "Library.h"

	class ModifyBooks : public ModifyingOperation{
	public:
		ModifyBooks(Library *l);
		virtual ~ModifyBooks();
	};

#endif