// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_BANK_H
#define MP_BANK_H

#include <string>
#include <iostream>

namespace mp
{
	/**
	 * @brief Stores all the money in the game.
	 */
	class CBank
	{
	public:
		CBank();
		CBank(float initialReserves);
		float Withdraw(float amount);
		void Deposit(float amount);
		float GetBalance();
	protected:
		float mReserves = 0;
	};
}

#endif
