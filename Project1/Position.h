#pragma once
#ifndef _Position_H_
#define _Position_H_
	#include "iostream"
	using namespace std;
	
	class Position{
		private:
			int roomID;
			int cabinetID;
			int shelfID;
		public:
			Position(int rID, int cID, int sID);
			Position(const Position &);
			friend ostream &operator<<(ostream &os, const Position &p){
				os << "Pozicija knjige:" << endl;
				os << "-Prostorija: " << p.roomID << endl;
				os << "-Orman: " << p.cabinetID << endl;
				os << "-Polica: " << p.shelfID;
				return os;
			}
	};

#endif