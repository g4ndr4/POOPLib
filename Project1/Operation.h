#pragma once
#ifndef _Operation_H_
#define _Operation_H_
	#include "Result.h"
	class Operation{
	public:
		Operation();
		virtual ~Operation();

		virtual void log() = 0;
		virtual void undo() = 0;
		virtual Result *execute() = 0;
	};
#endif
