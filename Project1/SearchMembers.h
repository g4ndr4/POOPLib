#pragma once
#ifndef _SearchMembers_H_
#define _SearchMembers_H_
#include "Library.h"
#include "SearchingOperation.h"
class SearchMembers : public SearchingOperation{
public:
	SearchMembers(Library *l);
	virtual ~SearchMembers();
};

#endif