#include "SetOfPublishers.h"

SetOfPublishers::SetOfPublishers(){}
SetOfPublishers::~SetOfPublishers(){}

bool SetOfPublishers::flag = false;

SetOfPublishers *SetOfPublishers::set = nullptr;

SetOfPublishers *SetOfPublishers::getInstance(){
	if (set == nullptr){
		set = new SetOfPublishers();
	}
	return set;
}

bool SetOfPublishers::findPublisher(string name){
	unordered_map<string, int>::iterator it = publishers.find(name);
	if (it == publishers.end()) return false;
	else return true;
}

void SetOfPublishers::addPublisher(string name){
	int id = ++curID;
	publishers.insert(std::make_pair(name, id));
}

int SetOfPublishers::curID = 0;