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
			unordered_map<int, File> file_storage;
		public:
			bool addFile(File f, int mmID);
			void removeFile(int membership_id);
			
			File *searchFilesByMembershipID(MyMembershipID *mID);

			Borrowing *searchByReturnDate(Date current_date, Date borrowing_date);

			Borrowing *searchByPeriod(Date date1, Date date2);
	};
	
#endif
