#pragma once
#include <string>
#include <map>
#include <iostream>

namespace BankSystem
{
	class Client
	{
	private:
		std::string name = "None";
		std::string birthday = "None";
		std::string address = "None";
		uint64_t phoneNumber = 0;
		typedef std::map<int, std::string> banksType;
		typedef std::map<int, std::pair<std::string, std::string>> credsType;
		banksType banks;
		credsType creds;
	public:
		Client() {}

		Client(std::string name, std::string birthday, std::string address, uint64_t phoneNumber)
			:
			name(name),
			birthday(birthday),
			address(address),
			phoneNumber(phoneNumber) {}

		~Client() {}
	public:
		void setName(std::string name) { this->name = name; }
		void setBirthday(std::string birthday) { this->birthday = birthday; }
		void setAddress(std::string address) { this->address = address; }
		void setPhoneNumber(uint64_t phoneNumber) { this->phoneNumber = phoneNumber; }
		void setCreds(int bankNumber, std::string login, std::string password);
		void setBankInfo(std::string bankName, int bankNumber);
	public:
		std::string getName() { return name; }
		std::string getBirthday() { return birthday; }
		std::string getAddress() { return address; }
		uint64_t getPhoneNumber() { return phoneNumber; }
		std::string getLogin(int bankNumber);
		std::string getPassword(int bankNumber);
	public:
		void info();
	};
}