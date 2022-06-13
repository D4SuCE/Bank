#include <iostream>
#include "bank.h"

namespace BankSystem
{
	void Bank::addClient(Client& client)
	{
		if (client.getName() != "None" && client.getBirthday() != "None" &&
			client.getAddress() != "None" && client.getPhoneNumber() != 0)
		{
			if (std::find_if(clients.begin(), clients.end(), [&](Client& client1)
				{
					return client1.getPhoneNumber() == client.getPhoneNumber();
				}) != clients.end())
			{
				std::cout << "\"" << client.getName() << "\" - already registered!" << std::endl;
			}
			else
			{
				client.setBankInfo(name, number);
				clients.push_back(client);
				std::cout << "\"" << client.getName() << "\" - added to " << name << "(" << number << ")" << "!" << std::endl;
			}
		}
		else
		{
			std::cout << "\"" << client.getName() << "\" - doesn`t fill all information!" << std::endl;
		}
	}

	void Bank::update(Client& client)
	{
		if (std::find_if(clients.begin(), clients.end(), [&](Client& client1)
			{
				return client1.getPhoneNumber() == client.getPhoneNumber();
			}) != clients.end())
		{
			for (auto& cl : clients)
			{
				if (cl.getPhoneNumber() == client.getPhoneNumber())
				{
					cl.setName(client.getName());
					cl.setBirthday(client.getBirthday());
					cl.setAddress(client.getAddress());
					cl.setCreds(number, client.getLogin(number), client.getPassword(number));
					std::cout << "\"" << client.getName() << "\" - updated to " << name << "(" << number << ")" << "!" << std::endl;
				}
			}
		}
		else
		{
			std::cout << "\"" << client.getName() << "\" - not found!" << std::endl;
		}
	}

	void Bank::info()
	{
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Name: " << name << std::endl;
		std::cout << "Address: " << address << std::endl;
		std::cout << "Number: " << number << std::endl;
		std::cout << "Count of clients: " << clients.size() << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}

	void Bank::fullInfo()
	{
		for (int i = 0; i < clients.size(); i++)
		{
			std::cout << "-------------" << name << "-------------" << std::endl;
			std::cout << "Name: " << clients[i].getName() << std::endl;
			std::cout << "Birthday: " << clients[i].getBirthday() << std::endl;
			std::cout << "Address: " << clients[i].getAddress() << std::endl;
			std::cout << "Phone Number: " << clients[i].getPhoneNumber() << std::endl;
			std::cout << "Login: " << clients[i].getLogin(number) << std::endl;
			std::cout << "Password: " << clients[i].getPassword(number) << std::endl;
			std::cout << std::string(26 + name.size(), '-') << std::endl;
		}
	}

	void Bank::fullInfo(Client& client)
	{
		if (std::find_if(clients.begin(), clients.end(), [&](Client& client1)
			{
				return client1.getPhoneNumber() == client.getPhoneNumber();
			}) != clients.end())
		{
			for (auto& cl : clients)
			{
				if (cl.getPhoneNumber() == client.getPhoneNumber())
				{
					std::cout << "-------------" << name << "-------------" << std::endl;
					std::cout << "Name: " << cl.getName() << std::endl;
					std::cout << "Birthday: " << cl.getBirthday() << std::endl;
					std::cout << "Address: " << cl.getAddress() << std::endl;
					std::cout << "Phone Number: " << cl.getPhoneNumber() << std::endl;
					std::cout << "Login: " << cl.getLogin(number) << std::endl;
					std::cout << "Password: " << cl.getPassword(number) << std::endl;
					std::cout << std::string(26 + name.size(), '-') << std::endl;
				}
			}
		}
		else
		{
			std::cout << "\"" << client.getName() << "\" - not found!" << std::endl;
		}
	}
}