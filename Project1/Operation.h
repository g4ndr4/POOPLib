#pragma once
#ifndef _Operation_H_
#define _Operation_H_
	#include "Library.h"	
	#include "Result.h"
	class Operation{
		Library *library;
	public:
		Operation(Library *l);
		virtual ~Operation();

		virtual void log() = 0;
		virtual void undo() = 0;
		virtual Result *execute() = 0;
	};
#endif
