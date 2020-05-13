#pragma once
#include "account.h"
#include "simple_account.h"
#include "bonus_account.h"
#include "service_account.h"
#include "balanced_account.h"
#include "trim.h"
#include <fstream>
#include <map>
#include <utility>

enum accounttype
{
	simple,
	bonus,
	service,
	balanced,
	ignore,
	logtofile
};
class Manager
{
private:
	Account* account{};
	std::string input_str{};
	std::map<std::string, Account*> accounts;
	std::ifstream account2{ "C:/Users/Tyler/Desktop/account2.dat" };
	std::ifstream transact{ "C:/Users/Tyler/Desktop/transact.dat" };
	std::ofstream update{ "C:/Users/Tyler/Desktop/update.dat" };
	std::ofstream report{ "C:/Users/Tyler/Desktop/report.txt" };
	std::ofstream error{ "C:/Users/Tyler/Desktop/account.log" };
	int error_num{ 1 };
public:
	Manager() = default;

	accounttype convert(std::string& a)
	{
		if (a.substr(50, 1) == "A")
		{
			return simple;
		}
		else if (a.substr(50, 1) == "B")
		{
			return bonus;
		}
		else if (a.substr(50, 1) == "C")
		{
			return service;
		}
		else if (a.substr(50, 1) == "D")
		{
			return balanced;
		}
		else if (a.substr(50, 1) == "X")
		{
			return ignore;
		}
		else
		{
			return logtofile;
		}

	}

	Account* create() 
	{
		Account* input{};
		switch (convert(input_str))
		{
		case (simple):
		{
			input = new SimpleAcc();
			input->set_code(input_str.substr(0, 10));
			input->set_first_name(input_str.substr(10, 15));
			input->set_last_name(input_str.substr(25, 25));
			input->set_balance(std::stod(input_str.substr(51, 11)));
			return input;
		}
		case (bonus):
		{
			input = new BonusAcc();
			input->set_code(input_str.substr(0, 10));
			input->set_first_name(input_str.substr(10, 15));
			input->set_last_name(input_str.substr(25, 25));
			input->set_balance(std::stod(input_str.substr(51, 11)));
			return input;
		}
		case (service):
		{
			input = new ServiceAcc();
			input->set_code(input_str.substr(0, 10));
			input->set_first_name(input_str.substr(10, 15));
			input->set_last_name(input_str.substr(25, 25));
			input->set_balance(std::stod(input_str.substr(51, 11)));
			return input;
		}
		case (balanced):
		{
			input = new BalancedAcc();
			input->set_code(input_str.substr(0, 10));
			input->set_first_name(input_str.substr(10, 15));
			input->set_last_name(input_str.substr(25, 25));
			input->set_balance(std::stod(input_str.substr(51, 11)));
			return input;
		}
		case (ignore):
		{
			return nullptr;
		}
		case (logtofile):
		{

			return nullptr;
		}
		}

	}

	void process()
	{
		if (!account2)
		{
			throw std::runtime_error("Input stream could not be opened.");
		}
		if (!error)
		{
			throw std::runtime_error("Output stream could not be opened.");
		}
		while (!account2.eof())
		{
			if (!std::getline(account2, input_str, '\n'))
			{
				break;
			}
			if (input_str.length() < 62)
			{
				throw std::runtime_error("String is too small.");
			}
			if (input_str.length() > 62)
			{
				throw std::runtime_error("String is too big.");
			}
			account = create();
			if (this->account != nullptr)
			{
				auto i = accounts.insert({ account->get_code(), account });
				
			}
			else
			{
				if (convert(input_str) == ignore)
				{
					continue;
				}
				else if (convert(input_str) == logtofile)
				{
					error << error_num << ' ' << "invalid type" << '\n';
					error_num++;
					continue;
				}
			}
			}
		transaction();
		}

	void transaction()
	{
		
		auto search = accounts.begin();
		account = accounts.begin()->second;
		if (!update)
		{
			throw std::runtime_error("Output stream could not be opened.");
		}
		if (!transact)
		{
			throw std::runtime_error("Input stream could not be opened.");
		}
		if (!error)
		{
			throw std::runtime_error("Output stream could not be opened.");
		}
		while (search != accounts.end())
		{
			double trans;
			std::string temp_s;
			if (!std::getline(transact, temp_s, '\n'))
			{
				break;
			}
			trans = std::stod(temp_s.substr(10, 11));
			if (accounts.count(temp_s.substr(0,10)))
			{
				accounts[temp_s.substr(0, 10)]->set_balance(accounts[temp_s.substr(0, 10)]->get_balance() + trans);
				accounts[temp_s.substr(0, 10)]->monthly_update();
			}
			else
			{
				error << error_num << ' ' << "account not found" << '\n';
				error_num++;
				continue;
			}
		}
		auto i = accounts.begin();
		while (i != accounts.end())
		{
			//update account to file
			update << (accounts.find(i->second->get_code())->second->get_code()) << ',';
			update << (accounts.find(i->second->get_code())->second->get_first_name()) << ',';      
			update << (accounts.find(i->second->get_code())->second->get_last_name()) << ',';
			update << std::fixed << accounts.find(i->second->get_code())->second->type() << accounts.find(i->second->get_code())->second->get_balance() << '\n';
			//report account to file
			report << (accounts.find(i->second->get_code())->second->get_code()) << ',';
			report << (generic::trim_right(accounts.find(i->second->get_code())->second->get_first_name())) << ',';
			report << (generic::trim_right(accounts.find(i->second->get_code())->second->get_last_name())) << ',';
			report << std::fixed << (accounts.find(i->second->get_code())->second->get_balance()) << ',';
			report << (accounts.find(i->second->get_code())->second->type()) << '\n';
			i++;
		}

	}
	

};

