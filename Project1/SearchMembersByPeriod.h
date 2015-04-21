#pragma once
#ifndef _SearchMembersByPeriod_H_
	#define _SearchMembersByPeriod_H_
	#include "SearchMembers.h"
	#include "File.h"
	#include "Date.h"
	
	class SearchMembersByPeriod : public SearchMembers {
	private:
		Date period_begin;
		Date period_end;
	public:
		SearchMembersByPeriod(int bday, int bmonth, int byear, int eday, int emonth, int eyear, Library *l);
		~SearchMembersByPeriod();

		void log() override{}

		void undo() override{}
	
		Result *execute() override;
	};

#endif