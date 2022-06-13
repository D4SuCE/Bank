#include <iostream>
#include "client.h"

#pragma warning(disable: 4715)

namespace BankSystem
{
	std::string Client::getLogin(int bankNumber)
	{
		auto cred = creds.find(bankNumber);
		if (cred != creds.end())
		{
			return cred->second.first;
		}
	}

	std::string Client::getPassword(int bankNumber)
	{
		auto cred = creds.find(bankNumber);
		if (cred != creds.end())
		{
			return cred->second.second;
		}
	}

	void Client::setCreds(int bankNumber, std::string login, std::string password)
	{
		auto bank = banks.find(bankNumber);
		if (bank != banks.end())
		{
			creds.insert({ bankNumber, {login, password} });
		}
		else
		{
			std::cout << "\"" << name << "\" - not a member of bank with number: " << bankNumber << "!" << std::endl;
		}
	}

	void Client::setBankInfo(std::string bankName, int bankNumber)
	{
		banks.insert({ bankNumber, bankName });
	}

	void Client::info()
	{
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Birthday: " << birthday << std::endl;
		std::cout << "Address: " << address << std::endl;
		std::cout << "Phone Number: " << phoneNumber << std::endl;
		std::cout << "Banks:  { " << std::endl;
		for (const auto& bank : banks)
		{
			std::cout << "\t    " << bank.second << "(" << bank.first << "), " << std::endl;
		}
		std::cout << "\t}\n-----------------------------------------" << std::endl;
	}

}