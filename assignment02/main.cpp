#include <iostream>
#include <string>
#include <vector>

#include "Employee.h"
#include "Department.h"
#include "Floor.h"
#include "Office.h"

using namespace std;

int main() {
	vector<Floor*> floorList;
	vector<Department*> depList;

	int intInp;

	while (true) {

		cout << "Choose an option:" << endl;
		cout << "1) Add a new Employee record" << endl;
		cout << "2) Look up Employee by ID number" << endl;
		cout << "3) List employees in a Department" << endl;
		cout << "4) List employees on Floor" << endl << endl;

		cin >> intInp;
		std::cin.ignore(10000, '\n');
		cout << endl;

		if (intInp == 1) {
			string empName;
			string depName;
			int empId;
			int offNum;

			Department* dep = 0;
			Floor* floor = 0;

			int floorNum;

			cout << "Enter employee name: ";
			getline(cin, empName);

			cout << "Enter employee ID number: ";
			cin >> empId;
			std::cin.ignore(10000, '\n');

			cout << "Enter department name: ";
			getline(cin, depName);

			cout << "Enter office number: ";
			cin >> offNum;
			std::cin.ignore(10000, '\n');

			for (int i = 0; i < depList.size(); i++) {
				if (depList.at(i)->getDepName() == depName) {
					dep = depList.at(i);
					break;
				}
			}
			if (!dep) {
				dep = new Department(depName);
				depList.push_back(dep);
			}

			floorNum = (offNum / 100);

			for (int i = 0; i < floorList.size(); i++) {
				if (floorList.at(i)->getFloorNum() == floorNum) {
					floor = floorList.at(i);
				}
			}
			if (!floor) {
				floor = new Floor(floorNum);
				floorList.push_back(floor);
			}

			Office* newOff = new Office(offNum, floor);
			floor->addOffice(newOff);

			Employee* newEmployee = new Employee(empName, empId, dep, newOff);
			newOff->setEmployee(newEmployee);
			dep->addEmployee(newEmployee);

			cout << endl;

			cout << "Added: " << empName << ", #" << empId << ", works in the " << dep->getDepName() << " department in office " << newOff->getOfficeNum() << "." << endl;

			cout << endl;
		}

		else if (intInp == 2) {
			int employeeId;
			bool found = false;

			cout << "Enter ID number: ";
			cin >> employeeId;
			std::cin.ignore(10000, '\n');
			cout << endl;

			for (int i = 0; i < depList.size(); i++) {
				vector<Employee*> employeeList = depList.at(i)->getEmployees();
				for (int j = 0; j < employeeList.size(); j++) {
					if (employeeList.at(j)->getId() == employeeId) {
						found = true;
						Employee* employee = employeeList.at(j);
						cout << employee->getName() << ", #" << employee->getId() << ", works in the " << employee->getDep()->getDepName() << " department in office " << employee->getOffice()->getOfficeNum() << "." << endl;
						break;
					}
				}
			}

			if (!found) {
				cout << "No employees under the ID #" << employeeId << "." << endl;
			}

			cout << endl;
		}

		else if (intInp == 3) {
			string depName;
			bool found = false;
			cout << "Enter department name: ";
			getline(cin, depName);
			cout << endl;

			for (int i = 0; i < depList.size(); i++) {
				if (depList.at(i)->getDepName() == depName) {
					found = true;
					cout << "The following employees work in the " << depList.at(i)->getDepName() << " department:" << endl;
					for (int j = 0; j < depList.at(i)->getEmployees().size(); j++) {
						cout << depList.at(i)->getEmployees().at(j)->getName() << ", #" << depList.at(i)->getEmployees().at(j)->getId() << endl;
					}
					break;
				}
			}

			if (!found) {
				cout << "Department '" << depName << "' does not exist." << endl;
			}

			cout << endl;
		}

		else if (intInp == 4) {
			int floor;
			bool found = false;
			cout << "Enter floor number: ";
			cin >> floor;
			std::cin.ignore(10000, '\n');
			cout << endl;

			for (int i = 0; i < floorList.size(); i++) {
				if (floorList.at(i)->getFloorNum() == floor) {
					found = true;
					cout << "The following employees work on Floor " << floorList.at(i)->getFloorNum() << ":" << endl;
					vector<Office*> officeList = floorList.at(i)->getOffices();
					for (int j = 0; j < officeList.size(); j++) {
						cout << officeList.at(j)->getEmp()->getName() << ", #" << officeList.at(j)->getEmp()->getId() << endl;
					}
					break;
				}
			}

			if (!found) {
				cout << "No employees work on Floor " << floor << "." << endl;
			}

			cout << endl;
		}

		else {
			cout << "Invalid option!" << endl << endl;
		}

	}

	return 0;
};