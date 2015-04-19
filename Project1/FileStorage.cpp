#include "FileStorage.h"


bool FileStorage::addFile(File f, int mmID){
	file_storage.insert(std::make_pair(mmID, f));
	return true;
}


void FileStorage::removeFile(int membership_id){
	file_storage.erase(membership_id);
}


File *FileStorage::searchFilesByMembershipID(MyMembershipID *mID){
	unordered_map<int, File>::iterator it = file_storage.find(mID->getMid());
	if (it == file_storage.end()) return nullptr;
	else return &(it->second);
}

Borrowing *FileStorage::searchByReturnDate(Date current_date, Date borrowing_date){
	vector<Borrowing *>borrowing_temp;
	int borrowing_count = 0;
	for (unordered_map<int, File>::iterator it = file_storage.begin(); it != file_storage.end(); ++it){
		it->second.searchByReturnDate(current_date, borrowing_date, borrowing_count, borrowing_temp);
	}

	int index = 0;
	cout << "Unesite redni broj pozajmice koju zelite da obradite ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0 || index > borrowing_count){
		cout << "GRESKA! Uneli ste nedozvoljeni broj!" << endl;
		return nullptr;
	}
	else return borrowing_temp[index - 1];
}

Borrowing *FileStorage::searchByPeriod(Date date1, Date date2){
	vector<Borrowing *>borrowing_temp;
	int borrowing_count = 0;
	for (unordered_map<int, File>::iterator it = file_storage.begin(); it != file_storage.end(); ++it){
		it->second.searchByPeriod(date1, date2, borrowing_count, borrowing_temp);
	}

	int index = 0;
	cout << "Unesite redni broj pozajmice koju zelite da obradite ili 0 ako ne zelite nijednu: "; cin >> index;
	if (index == 0 || index > borrowing_count){
		cout << "GRESKA! Uneli ste nedozvoljeni broj!" << endl;
		return nullptr;
	}
	else return borrowing_temp[index - 1];
}