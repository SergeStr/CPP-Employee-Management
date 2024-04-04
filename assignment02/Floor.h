#pragma once

#include <vector>

class Office;

class Floor
{
public:
	Floor(int flrNm);
	int getFloorNum();
	void addOffice(Office* off);
	std::vector<Office*> getOffices();
private:
	int floorNum;
	std::vector<Office*> offices;
};