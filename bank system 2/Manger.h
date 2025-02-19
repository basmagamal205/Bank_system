
#include"Helper.h"
#include "Datasource.h"
#pragma once
class FileManager :public DataSourceInterface
{
public:

	 static void addClient(Client c) {
		Helper::saveClient(c);
		}
	
	static void addEmployee(Employee e) {
		Helper::saveEmployee("Employees.txt","EmployeeLastId.txt",e);
		
	}
	static void addAdmin(Admin a) {
		Helper::saveEmployee("Admins.txt", "AdminLastId.txt", a);

		
	}
	static void  getAllClients() {
		Helper::getClients();
	}
	static void getAllEmployees() {
		Helper::getEmployees();
		}
		static void getAllAdmins() {
			Helper::getAdmins();
	}
	
		void removeAllClients() {
			Helper::clearFile("clients.txt", "ClientLastId.txt");
		}
		void removeAllEmployees() {
			Helper::clearFile("Employees.txt", "EmployeeLastId.txt");
		}
		void removeAllAdimns() {
			Helper::clearFile("Admins.txt", "AdminLastId.txt");
		}

		static void getAllData() {
			getAllAdmins();
			getAllClients();
			getAllEmployees();
		}

	};



