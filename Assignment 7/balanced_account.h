#pragma once
#include "account.h"

class BalancedAcc : public Account
{
public:
	BalancedAcc() = default;
	void monthly_update() override
	{
		Account::balance = Account::balance > 500.0 ? Account::balance * 1.05 : (Account::balance - 5.0) * 1.03;
	}

	char type() const override
	{
		return 'D';
	}

};