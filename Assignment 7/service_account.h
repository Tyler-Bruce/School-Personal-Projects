#pragma once
#include "account.h"

class ServiceAcc : public Account
{
public:
	ServiceAcc() = default;
	void monthly_update() override
	{
		Account::balance = (Account::balance - 5.0) * 1.04;
	}

	char type() const override
	{
		return 'C';
	}

};
