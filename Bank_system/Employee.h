#include <iostream>
#include<string>
#include <cctype>
#include "Validation.h"
#include "Person.h"
using namespace std;

#pragma once
class Employee :public Person
{protected:
	double salary;
public:
	Employee():Person() {
		this->salary = 0;
	}
	Employee(int id, string name, string password, double salary):Person(id,name,password) {
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

};


