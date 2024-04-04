#include "Office.h"

Office::Office(int offNum, Floor* floor) {
	this->offNum = offNum;
	this->floor = floor;
	this->emp = 0;
}

void Office::setEmployee(Employee* emp) {
	this->emp = emp;
}

int Office::getOfficeNum() {
	return offNum;
}

Floor* Office::getFloor() {
	return floor;
}

Employee* Office::getEmp() {
	return emp;
}
