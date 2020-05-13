#pragma once
#include "account.h"

class BonusAcc : public Account
{
public:
	BonusAcc() = default;
	void monthly_update() override
	{
		Account::balance = Account::balance*(Account::balance > 5000 ? 1.06 : 1.04);
	}

	char type() const override
	{
		return 'B';
	}


};
