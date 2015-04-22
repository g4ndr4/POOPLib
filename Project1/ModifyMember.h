#pragma once
#ifndef _ModifyMember_H_
	#define _ModifyMember_H_
	#include "ModifyingOperation.h"
	#include "Library.h"

	class ModifyMember : public ModifyingOperation{
	public:
		ModifyMember(Library *l);
		virtual ~ModifyMember();
	};

#endif