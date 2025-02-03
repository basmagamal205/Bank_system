#include <iostream>
#include<string>
#include <cctype>
#include "Validation.h"
#include "Person.h"

using namespace std;
#pragma once
class Client :public Person
{
	private:
		double balance;
	public:
		Client() : Person() {
			balance = 0;
		}
		Client(int id, string name, string password, double balance) : Person(id, name, password) {
			setBalance(balance);
		}
		//setter
		void setBalance(double balance) {
			if (Validation::validateBalance(balance))
				this->balance = balance;
			else cout << "Invalid balance\n";
		}
		//getter
		double getBalance() {
			return balance;
		}


};

