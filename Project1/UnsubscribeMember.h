#pragma once
#ifndef _UnsubscribeMember_H_
	#define _UnsubscribeMember_H_
	
	#include "ModifyMember.h"
	#include "Person.h"	
	class UnsubscribeMember : public ModifyMember{
	private:
		Person *person;
		int membership_id;
		MyMembershipID *mID;
	public:
		UnsubscribeMember(int mID, Library *l);
		~UnsubscribeMember();

		void log() override{}
		void undo() override;

		Result *execute() override;
	};

#endif