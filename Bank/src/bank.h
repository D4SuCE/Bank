#pragma once
#include <vector>
#include <string>
#include "client.h"
#include <iostream>

namespace BankSystem
{
	class Bank
	{
	private:
		std::string name = "None";
		std::string address = "None";
		int number = 0;
		std::vector<Client> clients;
	public:
		Bank() {}

		Bank(std::string name, std::string address, int number)
			:
			name(name),
			address(address),
			number(number) {}

		~Bank() {}
	public:
		void setName(std::string name) { this->name = name; }
		void setAddress(std::string address) { this->address = address; }
		void setNumber(int number) { this->number = number; }
	public:
		void addClient(Client& client);
		void update(Client& client);
	public:
		void info();
		void fullInfo();
		void fullInfo(Client& client);
	};
}