#pragma once

#include <string>
#include <vector>

class Employee;

class Department
{
public:
	Department(std::string dpNm);
	std::string getDepName();
	void addEmployee(Employee* emp);
	std::vector<Employee*> getEmployees();

private:
	std::string depName;
	std::vector<Employee*> employees;
};

