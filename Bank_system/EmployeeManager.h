#pragma once
#include "Employee.h"
#include "Client.h"
#include "FileManager.h"
#include "FilesHelper.h"
#include "Validation.h"
#include "ClientManager.h"


class EmployeeManager
{
public:
	static void printEmployeeMenu() {
        cout << "1-Display info" << endl;
        cout << "2-Add new Client" << endl;
        cout << "3-Search for client" << endl;
        cout << "4-List All clients" << endl;
        cout << "5-Edit client info" << endl;
        cout << "6-Change Password" << endl;
        cout << "7-Logout" << endl;
	}


    static void newClient(Employee* employee) {
        if (!employee) {
            cout << "Error: Invalid employee.\n";
            return;
        }

        Client client;
        client.setID(FilesHelper::getLast("ClientLastId.txt") + 1);

        string name, password;

        cout << "Enter client name: ";
        getline(cin, name);
        if (!Validation::validatename(name)) {
            cout << "Client not added due to invalid name.\n";
            return;
        }
        client.setName(name);

        cout << "Enter client password: ";
        getline(cin, password);
        if (!Validation::validatepassword(password)) {
            cout << "Client not added due to invalid password.\n";
            return;
        }
        client.setPassword(password);

        employee->addClient(client);
        FileManager::updateClients();

        cout << "\nClient added\n";
    }

    static void listAllClients(Employee* employee) {
      
        cout << "\nListing all clients:\n";
        employee->listClients();
    }

    static void searchForClient(Employee* employee) {
       
        int id;
        cout << "Enter client ID to search: ";
        cin >> id;

        Client* client = employee->searchClient(id);
        if (client) {
            cout << "\nClient found:\n";
            client->display();
        }
    }
    static void editClientInfo(Employee* employee) {
        int id;
        cout << "Enter client ID to edit: ";
        cin >> id;

        Client* client = employee->searchClient(id);
        if (!client) {
            cout << "Client not found.\n";
            return;
        }

        string name, password;
        double balance;

        cout << "Enter new name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter new password: ";
        getline(cin, password);
        cout << "Enter new balance: ";
        cin >> balance;

        if (Validation::validatename(name)) client->setName(name);
        if (Validation::validatepassword(password)) client->setPassword(password);
        if (Validation::validateBalance(balance)) client->setBalance(balance);

        FileManager::updateClients();
        cout << "Client info updated successfully!\n";
    }
    static Employee* login(int id, string password) {
        for (auto& employee : allEmployees) {
            if (employee.getId() == id && employee.getPassword() == password) {
                cout << "\nLogin successful. Welcome, " << employee.getName() << "!\n";
                return &employee;
            }
        }
        cout << "\nLogin failed: Invalid credentials.\n";
        return nullptr;
    }

    static bool employeeOptions(Employee* employee) {
        int choice;
        printEmployeeMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            employee->display();
            break;
        case 2:
            newClient(employee);
            break;
        case 3:
            searchForClient(employee);
            break;
        case 4:
            listAllClients(employee);
                break;
        case 5:
            editClientInfo(employee);
            break;
        case 6:
            ClientManager::updatePassword(employee);
            FileManager::updateEmployees();
            break;
        case 7:
            return false;
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
        return true;
    }

};

