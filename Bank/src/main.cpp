#include <iostream>
#include "bank.h"

using namespace BankSystem;

int main()
{
	Bank bank("National Money Bank", "Lenina 16a", 81365);
	Bank bank2("Money Reservation Bank", "Tretyakova 31b", 96356);

	Client client("Dima", "23.01.2002", "5 Augusta 8/16", 79041836920);

	bank.addClient(client);
	bank2.addClient(client);

	client.setCreds(81365, "D4SuCE", "PravayaRuka2002");
	client.setCreds(96356, "Hello", "World");

	bank.update(client);
	bank2.update(client);

	Client client2;
	client2.setName("Stas");
	client2.setBirthday("29.09.2002");
	client2.setAddress("Sobornaya 18");
	client2.setPhoneNumber(79163659387);

	bank.addClient(client2);
	bank2.addClient(client2);

	client2.setCreds(81365, "rpc4444", "SoSoK200292");
	client2.setCreds(96356, "TopProgrammist", "YeaBoy");

	bank.update(client2);
	bank2.update(client2);
	
	Client client3;
	client3.setName("Lena");
	client3.setBirthday("17.02.2003");
	client3.setAddress("Sobornaya 18");
	client3.setPhoneNumber(79513651894);

	bank.addClient(client3);
	bank2.addClient(client3);

	client3.setCreds(81365, "Fayleeklol", "LevayaNogaStasa2003");
	client3.setCreds(96356, "Fayleeklol", "LevayaNogaStasa2003");

	client3.setAddress("Yevropeyskaya 64");

	bank.update(client3);
	bank2.update(client3);
	
	return 0;
}