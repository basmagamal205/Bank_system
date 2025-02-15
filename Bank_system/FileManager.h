#include "Person.h"
#include "Client.h"
#include "Admin.h"
#include <fstream>
#include "DataSourceInterface.h"
using namespace std;
#pragma once
class FileManager :public DataSourceInterface
{
public:

	void addClient(Client c) {
		fstream clientsData;
		clientsData.open("Clients.txt", ios::app);
		if (clientsData.is_open()) {
			clientsData << c.getName() << '*' << c.getId() << '*' << c.getPassword() << '*' << c.getBalance() << '*';
			clientsData << "\n";
			clientsData.close();
		}
	}
	void addEmployee(Employee e) {
		fstream employeesData;
		employeesData.open("Employee.txt", ios::app);
		if (employeesData.is_open()) {
			employeesData << e.getName() << '*' << e.getId() << '*' << e.getPassword() << '*' << e.getSalary() << '*';
			employeesData << "\n";
			employeesData.close();
		}
	}
	void addAdmin(Admin a) {
		fstream adminsData;
		adminsData.open("Admin.txt", ios::app);
		if (adminsData.is_open()) {
			adminsData << a.getName() << '*' << a.getId() << '*' << a.getPassword() << '*' << a.getSalary() << '*';
			adminsData << "\n";
			adminsData.close();
		}
	}
	vector<Client> getAllClients() {
		vector<Client> clientsDataVector;
		string data;
		fstream clientsData;
		clientsData.open("Clients.txt", ios::in);
		if (clientsData.is_open()) {
			while (getline(clientsData, data)) {
				clientsDataVector.push_back(Parser::parseToClient(data));
			}
			clientsData.close();
		}
		return clientsDataVector;
	}
	vector<Employee> getAllEmployees() {
		vector<Employee> employeesDataVector;
		string data;
		fstream employeesData;
		employeesData.open("Employee.txt", ios::in);
		if (employeesData.is_open()) {
			while (getline(employeesData, data)) {
				{
					employeesDataVector.push_back(Parser::parseToEmployee(data));
				}
				employeesData.close();
			}
			return employeesDataVector;
		}
		
	}
	vector<Admin> getAllAdmins() {
		vector<Admin> adminsDataVector;
		string data;
		fstream adminsData;
		adminsData.open("Admin.txt", ios::in);
		if (adminsData.is_open()) {
			while (getline(adminsData, data)) {
				adminsDataVector.push_back(Parser::parseToAdmin(data));
			}
			adminsData.close();
		}
		return adminsDataVector;
	}

	static void updateClients() {
		ofstream clientsData("Clients.txt", ios::out); // Open in write mode (overwrite file)

		if (!clientsData.is_open()) {
			return;
		}

		for (auto& client : allClients) {
			clientsData << client.getId() << '&'
				<< client.getName() << '&'
				<< client.getPassword() << '&'
				<< client.getBalance() << "\n";
		}

		clientsData.close();
		cout << " Clients updated successfully.\n";
	}
	static void updateEmployees() {
		ofstream Employeesdata("Clients.txt", ios::out); // Open in write mode (overwrite file)

		if (!Employeesdata.is_open()) {
			return;
		}

		for (auto& Employee : allEmployees) {
			Employeesdata << Employee.getId() << '&'
				<< Employee.getName() << '&'
				<< Employee.getPassword() << '&'
				<< Employee.getSalary() << "\n";
		}

		Employeesdata.close();
		cout << " Clients updated successfully.\n";
	}

	void removeAllClients() {
		fstream clientsData;
		clientsData.open("Clients.txt", ios::out);
		clientsData.clear();
		clientsData.close();
	}
	void removeAllEmployees() {
		fstream employeesData;
		employeesData.open("Employees.txt", ios::out);
		employeesData.clear();
		employeesData.close();
	}
	void removeAllAdimns() {
		fstream adminsData;
		adminsData.open("Admins.txt", ios::out);
		adminsData.clear();
		adminsData.close();
	}


};
