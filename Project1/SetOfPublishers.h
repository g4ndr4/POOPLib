#pragma once
#ifndef _SetOfPublishers_H_
	#define _SetOfPublishers_H_
	#include <iostream>
	#include <string>
	#include <unordered_map>
	using namespace std;

	class SetOfPublishers{
	private:
		static int curID;
		unordered_map<string, int> publishers;
		static bool flag;
		static SetOfPublishers *set;
		SetOfPublishers();
		SetOfPublishers(SetOfPublishers const&) = delete;
		SetOfPublishers operator=(SetOfPublishers const&) = delete;
		//premestanje

	public:
		static SetOfPublishers *getInstance();
		~SetOfPublishers();

		bool findPublisher(string name);
		void addPublisher(string name);
		void removePublisher(string name);

	};

#endif