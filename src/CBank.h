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
		/**
		 * @brief Withdraw an amount from the bank.
		 */
		float Withdraw(float amount);
		/**
		 * @brief Deposit an amount into the bank.
		 */
		void Deposit(float amount);
		/**
		 * @brief Get the bank's balance.
		 */
		float GetBalance();
	protected:
		float mReserves = 0;
	};
}

#endif
