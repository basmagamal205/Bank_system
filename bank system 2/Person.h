#include <iostream>
#include<string>
#include <cctype>
#include "Validation.h"
using namespace std;
#pragma once
class Person
{
protected:
	int id;
	string name, password;
public:
	Person() {
		id = 0;
		name = "";
		password = "";
	}
	Person(int id, string name, string password) {
		setID(id);
		setName(name);
		setPassword(password);
	}
	//setter
	void setName(string name) {
		if (Validation::validatename(name))
			this->name = name;
		else cout << "Invalid name\n";
	}

	void setPassword(string password) {
		if (Validation::validatepassword(password))
			this->password = password;
		else cout << "Invalid password\n";
	}


	void setID(int id) {
		this->id = id;
	}
	//getter
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	int getId() {
		return id;
	}
	//method
	void display() {
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Password : " << password << endl;
	}

   



};
