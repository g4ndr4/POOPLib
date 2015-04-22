#include "FileStorage.h"


bool FileStorage::addFile(File f, int mmID){
	file_storage.insert(std::make_pair(mmID, f));
	return true;
}


void FileStorage::removeFile(int membership_id){
	file_storage.erase(membership_id);
}

bool FileStorage::searchForExistingSubscription(long jmbg){
	for (auto it : file_storage) if (it.second.getPerson().getPID().getJmbg() == jmbg) return true;
	return false;
}


File *FileStorage::searchFilesByMembershipID(MyMembershipID *mID){
	unordered_map<int, File>::iterator it = file_storage.find(mID->getMid());
	if (it == file_storage.end()) return nullptr;
	else return &(it->second);
}

vector<File *> *FileStorage::searchByReturnDate(Date current_date, Date borrowing_date){
	vector<File *> *result = new vector<File *>;
	for (unordered_map<int, File>::iterator it = file_storage.begin(); it != file_storage.end(); ++it){
		if (File *temp_file = it->second.searchByReturnDate(current_date, borrowing_date)) result->push_back(temp_file);
	}
	return result;
}

vector<File *> *FileStorage::searchByPeriod(Date period_begin, Date period_end){
	vector<File *> *result = new vector<File *>;
	for (unordered_map<int, File>::iterator it = file_storage.begin(); it != file_storage.end(); ++it){
		if (File *temp_file = it->second.searchByPeriod(period_begin, period_end)) result->push_back(temp_file);
	}
	return result;
}