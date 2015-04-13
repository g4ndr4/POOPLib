#pragma once
#ifndef _MyMembershipID_H_
#define _MyMembershipID_H_
	#include "MembershipID.h"
	class MyMembershipID : public MembershipID{
		private:
			MyMembershipID();
			MyMembershipID(const MyMembershipID &mid);
			MyMembershipID &operator=(const MyMembershipID &mid);
		public:
			MyMembershipID(PersonalID &pid) : MembershipID(pid){}
			int getMid() const override;
	};

#endif