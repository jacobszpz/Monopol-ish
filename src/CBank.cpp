// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <string>
#include "CBank.h"

using namespace std;
using namespace mp;

CBank::CBank()
{
}

CBank::CBank(float initialReserves) : mReserves(initialReserves)
{
}

float CBank::Withdraw(float amount)
{
	float withdrawn = 0;

	// Only transact if reserves allow it
	if (mReserves >= amount)
	{
		mReserves -= amount;
		withdrawn = amount;
	}

	return withdrawn;
}

void CBank::Deposit(float amount)
{
	mReserves += amount;
}

float CBank::GetBalance()
{
	return mReserves;
}
