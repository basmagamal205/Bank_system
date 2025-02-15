#include "Client.h"
#include "Employee.h"
#include "Person.h"
#pragma once

class ClientManager : public Employee {
public:

	static void printclientmenu() {
		cout << "1-Deposit" << endl;
		cout << "2-Withdraw" << endl;
		cout << "3-Transfer" << endl;
		cout << "4-Check Balance" << endl;
		cout << "5-Change Password" << endl;
		cout << "6-Logout" << endl;
	}

	//========================================
	static void updatePassword(Person* person) {
		cout << "Enter your ID:" << endl;
		int id;
		cin >> id;
		cout << "Enter new password:" << endl;
		string newpassword;
		cin >> newpassword;
		if (id == person->getId()) {
			person->setPassword(newpassword);
		}
		else {
			cout << "Invalid ID" << endl;
		}
	}

	//===========================================
	static Client* login(int id, string password) {
		cout << "Enter your ID:" << endl;
		cin >> id;
		if (id == allClients[0].getId()) {
			cout << "Enter your password:" << endl;
			cin >> password;
			if (password == allClients[0].getPassword()) {
				cout << "Login successful" << endl;
				return &allClients[0];
			}
			else {
				cout << "Invalid password" << endl;
			}
		}
		else {
			cout << "Invalid ID" << endl;
		}
		return nullptr;
	}

	//===========================================
	static bool clientOptions(Client* client) {
		printclientmenu();

		int choice;
		Client* recipient = nullptr; 
		cin >> choice;

		switch (choice) {
		case 1: {
			double amount;
			cout << "Enter amount to deposit" << endl;
			cin >> amount;
			client->deposit(amount);
			break;
		}
		case 2: {
			double amount2;
			cout << "Enter amount to withdraw" << endl;
			cin >> amount2;
			client->withdraw(amount2);
			break;
		}
		case 3: {
			double amount3;
			int id;
			cout << "Enter amount to transfer" << endl;
			cin >> amount3;
			cout << "Enter recipient ID" << endl;
			cin >> id;

			recipient = Employee::searchClient(id);
			if (recipient != nullptr) {
				client->transferTo(amount3, *recipient);
			}
			else {
				cout << "Recipient not found." << endl;
			}
			break;
		}
		case 4:
			client->checkBalance();
			break;
		case 5:
			updatePassword(client);
			break;
		case 6:
			return false;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
		return true;
	}
};
