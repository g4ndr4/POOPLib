#pragma once
#ifndef _SubscribeMember_H_
	#define _SubscribeMember_H_
	#include "ModifyMember.h"
	#include "Person.h"
	class SubscribeMember : public ModifyMember{
	private:
		Person *person;
	public:
		SubscribeMember(Person *person, Library *l);
		~SubscribeMember();

		void log() override{}

		void undo() override;

		Result *execute() override;
	};

#endif