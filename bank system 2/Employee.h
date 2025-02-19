
#include "Person.h"
#include "client.h"
using namespace std;

#pragma once
class Employee :public Person
{
protected:
	double salary;
public:
	Employee() :Person() {
		this->salary = 0;
	}
	Employee(int id, string name, string password, double salary) :Person(id, name, password) {
		setSalary(salary);

	}

	void setSalary(double salary) {
		if (Validation::validateSalary(salary)) {
			this->salary = salary;
		}
		else cout << "Invalid salary\n";
	}
	double getSalary() {
		return salary;
	}
	void display() {
		cout << "ID: " << id << endl;
		cout << "===================" << endl;
		cout << "Name: " << name << endl;
		cout << "===================" << endl;
		cout << "Passowrd: " << password << endl;
		cout << "===================" << endl;
		cout << "Salary: " << salary << endl;
		cout << "===================" << endl;
	}
	void addClient(Client& client) {
		allClients.push_back(client);
	}



	Client searchClient(int id) {
		for (auto& client :allClients) {
			if (client.getId() == id) {
				return client;
			}
		}
		return Client();
	}



	void listClients() {
		for (auto& client : allClients) {
			client.display();
		}
	}

	void editClient(int id, string name, string password, double balance) {
		for (auto& client : allClients) {
			if (client.getId() == id) {
				client.setName(name);
				client.setPassword(password);
				client.setBalance(balance);

			}
		}
		return;
	}
	
	
};
static vector<Employee> allEmployees;
static vector <Employee> ::iterator empIt;
