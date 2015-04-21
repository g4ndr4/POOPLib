#pragma once
#ifndef _SearchMembersbyReturnDate_H_
	#define _SearchMembersbyReturnDate_H_
	#include "SearchMembers.h"
	#include "Library.h"
	#include "Date.h"
	#include "Result.h"
	class SearchMembersByReturnDate : public SearchMembers{
	private:
		Date current_date;
		Date borrowing_date;
	public:
		SearchMembersByReturnDate(int cday, int cmonth, int cyear, int bday, int bmonth, int byear, Library *l);
		~SearchMembersByReturnDate();

		void log() override{}

		void undo() override{}

		Result *execute() override;
	};

#endif