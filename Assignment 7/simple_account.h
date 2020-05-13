#pragma once
#include "account.h"

class SimpleAcc : public Account
{
public:
	SimpleAcc() = default;
	void monthly_update() override
	{
		Account::balance *= 1.05;
	}

	char type() const override
	{
		return 'A';
	}


	
};
