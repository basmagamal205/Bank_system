#include <iostream>
#include<string>
#include <vector>
#include <cctype>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
using namespace std;

#pragma once
class Employee :public Person
{
private:
	
protected:
	vector<Client> Clients;
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

	//Methods
	void display() {
		cout << "ID: " << id << "  " << "Name: " << name << "  " << "Passowrd: " << password << "Salary: " << salary << "  " << endl;

	}


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
};


