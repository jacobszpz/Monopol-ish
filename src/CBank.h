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
		static float Withdraw(float amount);
		static void Deposit(float amount);
	protected:
		static float mReserves;
	};
}

#endif
