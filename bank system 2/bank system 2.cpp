
#include <iostream>
#include<string>
#include <cctype>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include"Helper.h"
#include "Admin.h"
#include <fstream>
using namespace std;

int main()
{
	ofstream file1;
	file1.open("Employees.txt");
	file1.close();

	ofstream fileadmin;
	fileadmin.open("Admins.txt");
	fileadmin.close();

	ofstream file;
	file.open("ClientLastId.txt", ios::out);
	file << "1";
	file.close();

	ofstream file2;
	file2.open("EmployeeLastId.txt");
	file2 << "11";
	file2.close();

	ofstream file3;
	file3.open("AdminLastId.txt");
	file3 << "111";
	file3.close();

	Client c1(111, "ahmed", "2134545667", 3000);
	Employee e1(123, "basma", "1234567gh", 12000);
	Admin a1(123, "yahia", "56ffasss", 12000);
	Helper::saveEmployee("admin.txt", "AdminLastId.txt", a1);
	
}