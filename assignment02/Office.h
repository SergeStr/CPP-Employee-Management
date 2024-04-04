#pragma once

class Floor;
class Employee;

class Office
{
public:
	Office(int ofNum, Floor* flr);
	void setEmployee(Employee* emp);
	int getOfficeNum();
	Floor* getFloor();
	Employee* getEmp();
private:
	int offNum;
	Floor* floor;
	Employee* emp;
};

