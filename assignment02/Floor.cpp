#include "Floor.h"


Floor::Floor(int floorNum) {
	this->floorNum = floorNum;
};

int Floor::getFloorNum() {
	return floorNum;
}

void Floor::addOffice(Office* off) {
	offices.push_back(off);
}

std::vector<Office*> Floor::getOffices() {
	return offices;
}