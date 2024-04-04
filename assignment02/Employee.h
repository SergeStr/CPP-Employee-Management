#pragma once

#include <string>

class Office;
class Department;

class Employee
{
public:
	Employee(std::string name, int id, Department* dep, Office* off);
	int getId();
	std::string getName();
	Department* getDep();
	Office* getOffice();

private:
	std::string name;
	int id;
	Department* dep;
	Office* off;
};

