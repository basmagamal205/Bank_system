#include <iostream>
#include<string>
#include <cctype>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include<vector>
#include "Admin.h"
#include <fstream>
using namespace std;
#pragma once
class Parser
{
public:
	static vector<string> split(string line) {
		vector<string> vec;
		vec.push_back(line);
		return vec;
	}
	//=================================================
	static Client parseToClient(string line) {
		Client c;
		int count{};
		while (count <= 3) {
			if (count == 0) {
				c.setName(line.substr(0, line.find('*', 0)));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else if (count == 1) {
				c.setID(stoi(line.substr(0, line.find('*', 0))));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else if (count == 2) {
				c.setPassword(line.substr(0, line.find('*', 0)));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else {
				c.setBalance(stod(line.substr(0, line.find('*', 0))));
				count++;
			}
		}
		return c;
	}
	//================================================
	static Employee parseToEmployee(string line) {
		Employee e;
		int count{};
		while (count <= 3) {
			if (count == 0) {
				e.setName(line.substr(0, line.find('*', 0)));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else if (count == 1) {
				e.setID(stoi(line.substr(0, line.find('*', 0))));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else if (count == 2) {
				e.setPassword(line.substr(0, line.find('*', 0)));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else {
				e.setSalary(stod(line.substr(0, line.find('*', 0))));
				count++;
			}
		}
		return e;
	}
	//==============================================
	static Admin parseToAdmin(string line) {
		Admin a;
		int count{};
		while (count <= 3) {
			if (count == 0) {
				a.setName(line.substr(0, line.find('*', 0)));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else if (count == 1) {
				a.setID(stoi(line.substr(0, line.find('*', 0))));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else if (count == 2) {
				a.setPassword(line.substr(0, line.find('*', 0)));
				line.erase(0, line.find('*', 0) + 1);
				count++;
			}
			else {
				a.setSalary(stod(line.substr(0, line.find('*', 0))));
			}
		}
	}
};


