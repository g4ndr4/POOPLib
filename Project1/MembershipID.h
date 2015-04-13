#pragma once
#ifndef _MembershipID_H_
#define _MembershipID_H_
	#include "PersonalID.h"
	#include "iostream"
	#include "cmath"
	#include "string"
	using namespace std;

	class MembershipID{
		private:
			static int curID;
			int id;
			MembershipID();
			MembershipID(const MembershipID &mid){}
			MembershipID &operator=(const MembershipID &mid){}
		public:
			MembershipID(PersonalID &pid);

			virtual ~MembershipID(){};

			virtual int getMid() const;

			friend ostream &operator<<(ostream &os, const MembershipID &mid){
				return os << mid.getMid();
			}

	};
#endif
