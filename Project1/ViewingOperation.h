#pragma once
	#include "Library.h"
	#include "Operation.h"
	class ViewingOperation : public Operation{
	public:
		ViewingOperation(Library *l);
		~ViewingOperation();
	};

