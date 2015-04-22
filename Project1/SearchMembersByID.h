#pragma once
#ifndef _SearchMembersByID_H_
	#define _SearchMembersByID_H_
	#include "SearchMembers.h"
	class SearchMembersByID : public SearchMembers{
	private:
		int membership_id;
	public:
		SearchMembersByID(int mID, Library *l);
		~SearchMembersByID();

		void log() override{}
		void undo() override{}

		Result *execute() override;
	};

#endif