#include <fstream>
#include <string>
#include <vector>
#include "Parser.h"
#include "Client.h"
using namespace std;

class Helper {
public:
	static void saveLast(string fileName, int id) {
		ofstream file;
		file.open(fileName);
		file << id;
		file.close();
	}
	//=============================================
	static int getLast(string fileName) {
		ifstream file(fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}
	/*ifstream file(fileName);
			string s;
			getline(file, s);
			int id
				id= stoi(s);
				file.close();
			return id;
		}*/
		//===============================================
	static void saveClient(Client c) {
		int id = getLast(" ClientLastId.txt");
		std::fstream file;
		file.open("Clients.txt", ios::app);
		file << id + 1 << '&' << c.getName() << '&' << c.getPassword() << '&' << c.getBalance() << "\n";
		file.close();
		saveLast("ClientLastId.txt", id + 1);
	}
	//====================================================================
	static void saveEmployee(string fileName, string lastIdFile, Employee e) {
		int id = getLast(lastIdFile);
		fstream file;
		file.open(fileName, ios::app);
		file << id + 1 << '&' << e.getName() << '&' << e.getPassword() << '&' << e.getSalary() << "\n";
		file.close();
		saveLast(lastIdFile, id + 1);
	}
	//=====================================================================
	static void getClients() {
		string line;
		ifstream file;
		file.open("Clients.txt");
		vector<Client>allClients;
		while (getline(file, line)) {
			Client c = Parser::parseToClient(line);
			allClients.push_back(c);

		}
		file.close();
	}
	//=========================================================
	static void getEmployees() {
		string line;
		ifstream file;
		file.open("Employees.txt");
		vector<Employee>allEmployees;
		while (getline(file, line)) {
			Employee e = Parser::parseToEmployee(line);
			allEmployees.push_back(e);
			file.close();
		}
	}
	//==================================================
	static void getAdmins() {
		string line;
		ifstream file;
		file.open("Admins.txt");
		vector<Admin>allAdmins;
		while (getline(file, line)) {
			Admin a = Parser::parseToAdmin(line);
			allAdmins.push_back(a);
		}
		file.close();
	}


	//===================================================
	static void clearFile(string fileName, string lastIdFile) {
		fstream file1, file2;
		file1.open(fileName, ios::out);
		file1.close();
		file2.open(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}
};
