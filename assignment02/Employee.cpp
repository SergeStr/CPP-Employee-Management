#include <string>

#include "Employee.h"
#include <iostream>


Employee::Employee(std::string name, int id, Department* dep, Office* off) {
	this->name = name;
	this->id = id;
	this->dep = dep;
	this->off = off;
};

int Employee::getId() {
	return id;
};

std::string Employee::getName() {
	return name;
};

Department* Employee::getDep() {
	return dep;
};

Office* Employee::getOffice() {
	return off;
};


