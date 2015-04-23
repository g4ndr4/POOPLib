#pragma once
#ifndef _FileStorage_H_
	#define _FileStorage_H_
	#include "File.h"
	#include "File.h"
	#include "iostream"
	#include "unordered_map"
	using namespace std;
	
	class FileStorage{
		private:
			unordered_map<int, File *> file_storage;
		public:
			bool addFile(File *f, int mmID);
			void removeFile(int membership_id);
			
			void setMember(bool status, int membership_id);

			File *searchForExistingSubscription(long jmbg);
			bool isMember(int membership_id);
			Person *unsubscribeMember(int membership_id);

			File *searchFilesByMembershipID(int membership_id);

			vector<File *> *searchByReturnDate(Date current_date, Date borrowing_date);

			vector<File *> *searchByPeriod(Date period_begin, Date period_end);
	};
	
#endif
