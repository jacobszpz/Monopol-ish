// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <string>
#include "CBank.h"

using namespace std;
using namespace mp;

float CBank::Withdraw(float amount)
{
	float withdrawn = 0;

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
