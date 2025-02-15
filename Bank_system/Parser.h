#include<sstream>
#include<vector>
#include "Admin.h"
using namespace std;
#pragma once
class Parser
{
private:
	static vector<string> split(string line) {
		stringstream str(line);
		string token;
		vector<string> info;
		while (getline(str, token, '&'))
		{
			info.push_back(token);
		}

		return info;
	}
	//=================================================
public:
	static Client parseToClient(string line) {
		vector<string> info = split(line);
		Client c;
		c.setID(stoi(info[0]));
		c.setName(info[1]);
		c.setPassword(info[2]);
		c.setBalance(stod(info[3]));
		return c;
	}
	//================================================
	static Employee parseToEmployee(string line) {
		vector<string> info = split(line);
		Employee e;
		e.setID(stoi(info[0]));
		e.setName(info[1]);
		e.setPassword(info[2]);
		e.setSalary(stod(info[3]));
		return e;
	}
	//==============================================
	static Admin parseToAdmin(string line) {
		vector<string> info = split(line);
		Admin a;
		a.setID(stoi(info[0]));
		a.setName(info[1]);
		a.setPassword(info[2]);
		a.setSalary(stod(info[3]));
		return a;
	}
};