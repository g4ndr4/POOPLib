#include "Position.h"


Position::Position(int rID, int cID, int sID){
	roomID = rID;
	cabinetID = cID;
	shelfID = sID;
}

Position::Position(const Position &pos){
	roomID = pos.roomID;
	cabinetID = pos.cabinetID;
	shelfID = pos.shelfID;
}
