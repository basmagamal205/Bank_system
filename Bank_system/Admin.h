
#include "Person.h"
#include "Employee.h"
using namespace std;

#pragma once
class Admin :public Employee
{
private:
	vector<Employee> allEmployees;


public:
	Admin() :Employee()
	{
	}
	Admin(int id, string name, string password, double salary)
		:Employee(id, name, password, salary) {
	}


	//methods:
	void addEmployee(Employee& Employee) {
		allEmployees.push_back(Employee);
	}

	Employee* searchEmployee(int id) {
		for (auto& Employee : allEmployees) {
			if (Employee.getId() == id) {
				return &Employee;
			}
			else {
				cout << "Employee not found" << endl;
				return nullptr;

			}
		}
	}

	void listEmployee() {
		for (auto& Employee : allEmployees) {
			Employee.display();
		}
	}

	void editEmployee(int id, string name, string password, double salary) {
		for (auto& Employee : allEmployees) {
			if (Employee.getId() == id) {
				Employee.setName(name);
				Employee.setPassword(password);
				Employee.setSalary(salary);

			}
		}
		return;
	}










};
static vector<Admin> allAdmins;
static vector <Admin> ::iterator adIt;