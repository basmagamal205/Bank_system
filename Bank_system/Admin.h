#include <cctype>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"
using namespace std;

#pragma once
class Admin :public Employee
{
private:
	vector<Employee> Employees;
public:
	Admin() :Employee()
	{}
	Admin(int id, string name, string password, double salary)
		:Employee(id,name,password,salary)
		
	{}

	void addClient(Client& client) {
		Clients.push_back(client);
	}

	Client searchClient(int id) {
		for (auto& client : Clients) {
			if (client.getID() == id) {
				return client;
			}
		}
		return Client();
	}


	void listClients() {
		for (auto& client : Clients) {
			client.display();
		}
	}

	void editClient(int id, string name, string password, double balance) {
		for (auto& client : Clients) {
			if (client.getID() == id) {
				client.setName(name);
				client.setPassword(password);
				client.setBalance(balance);

			}
		}
		return;
	}
	//==========================

	void addEmployee(Employee& Employee) {
		Employees.push_back(Employee);
	}

	Employee searchEmployee(int id) {
		for (auto& Employee : Employees) {
			if (Employee.getID() == id) {
				return Employee;
			}
		}
		return Employee();
	}

	void listEmployee() {
		for (auto& Employee : Employees) {
			Employee.display();
		}
	}

	void editEmployee(int id, string name, string password, double salary) {
		for (auto& Employee : Employees) {
			if (Employee.getID() == id) {
				Employee.setName(name);
				Employee.setPassword(password);
				Employee.setSalary(salary);

			}
		}
		return;
	}
};

