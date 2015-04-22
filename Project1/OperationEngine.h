#pragma once
#ifndef _OperationEngine_H_
#define _OperationEngine_H_
	#include <iostream>
	#include "Operation.h"
	#include "Result.h"
	class OperationEngine
	{
	public:
		OperationEngine();
		~OperationEngine();

		void enableLogging();
		void undo(Operation *o);
		Result *submitOperation(Operation *o);
	};

#endif;