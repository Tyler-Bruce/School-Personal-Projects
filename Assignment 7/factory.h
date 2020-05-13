#pragma once
#include "account.h"
#include "simple_account.h"
#include "bonus_account.h"
#include "service_account.h"
#include "balanced_account.h"
#include "trim.h"
#include <fstream>
enum accounttype
{
	simple,
	bonus,
	service,
	balanced
};
class Factory
{
private:
	std::ifstream account2{ "C:/Users/Tyler/Desktop/account2.dat" };
public:
	accounttype convert(std::string& a)
	{
		if (a.substr(50, 1) == "A")
		{
			return simple;
		}
		if (a.substr(50, 1) == "B")
		{
			return bonus;
		}
		if (a.substr(50, 1) == "C")
		{
			return service;
		}
		if (a.substr(50, 1) == "D")
		{
			return balanced;
		}
	}
	Account *read() //Ask about factory function
	{	
		
		/*if (a.substr(50, 1) == "X")
		{
			continue;
		}*/
		switch (convert()
		{
		case ('A'):
		{
			Account* input = new SimpleAcc();
			input->set_code(a.substr(0, 10));
			input->set_first_name(a.substr(10, 15));
			input->set_last_name(a.substr(25, 25));
			input->set_balance(std::stod(a.substr(51, 11)));
			return input;
		}
		case ('B'):
		{
			Account* input = new BonusAcc();
			input->set_code(a.substr(0, 10));
			input->set_first_name(a.substr(10, 15));
			input->set_last_name(a.substr(25, 25));
			input->set_balance(std::stod(a.substr(51, 11)));
			return input;
		}
		case ('C'):
		{
			Account* input = new ServiceAcc();
			input->set_code(a.substr(0, 10));
			input->set_first_name(a.substr(10, 15));
			input->set_last_name(a.substr(25, 25));
			input->set_balance(std::stod(a.substr(51, 11)));
			return input;		
		}
		case ('D'):
		{
			Account* input = new BalancedAcc();
			input->set_code(a.substr(0, 10));
			input->set_first_name(a.substr(10, 15));
			input->set_last_name(a.substr(25, 25));
			input->set_balance(std::stod(a.substr(51, 11)));
			return input;
		}
		case ('X'):
		{
			break;
		}
		}
			
		return nullptr;
		
	}
};