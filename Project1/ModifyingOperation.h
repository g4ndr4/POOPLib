#pragma once
#ifndef _ModifyingOperation_H_
	#define _ModifyingOperation_H_
	#include "Operation.h"
	#include "Library.h"
	
	class ModifyingOperation : public Operation{
	public:
		ModifyingOperation(Library *l);
		virtual ~ModifyingOperation();
	};
#endif
