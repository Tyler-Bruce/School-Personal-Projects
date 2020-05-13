#pragma once
#include <string>
#include <iostream>

class Account
{
public: 
	std::string account_code;
	std::string first_name;
	std::string last_name;
	double balance;

	Account(const std::string& ac, const std::string& fn, const std::string& ln, const double& b):
		account_code{ac},
		first_name{fn},
		last_name{ln},
		balance{b}
	{}

	Account() = default;
	
	Account(Account& a) = default;

	virtual void monthly_update() = 0;

	virtual char type() const = 0;

	void set_code(const std::string& code)
	{
		account_code = code;
	}
	void set_first_name(const std::string& first)
	{
		first_name = first;
	}
	void set_last_name(const std::string& last)
	{
		last_name = last;
	}
	void set_balance(const double& bal)
	{
		balance = bal;
	}

	double get_balance()
	{
		return balance;
	}

	std::string get_code()
	{
		return account_code;
	}

	std::string get_first_name()
	{
		return first_name;
	}

	std::string get_last_name()
	{
		return last_name;
	}

	friend std::ostream& operator<<(std::ostream& s, const Account& a)
	{
		return s << a.account_code << ',' << a.first_name << ',' << a.last_name << ',' << a.balance << '\n';
	}

};

