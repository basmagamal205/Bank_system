#include <cctype>
#include "Validation.h"
#include "Person.h"
#include "Employee.h"
using namespace std;

#pragma once
class Admin :public Employee
{

public:
	Admin() :Employee()
	{}
	Admin(int id, string name, string password, double salary)
		:Employee(id,name,password,salary)
		
	{}
};

