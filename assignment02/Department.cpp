#include "Department.h"

Department::Department(std::string depName) {
	this->depName = depName;
}

std::string Department::getDepName() {
	return depName;
}

void Department::addEmployee(Employee* emp) {
	employees.push_back(emp);
}

std::vector<Employee*> Department::getEmployees() {
	return employees;
}