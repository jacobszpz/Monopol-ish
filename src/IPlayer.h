// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_I_PLAYER_H
#define MP_I_PLAYER_H

#include <string>
#include "EPiece.h"
#include "ESquareType.h"

namespace mp
{
	/**
	 * @brief Represents a player of the game.
	 */
	class IPlayer
	{
	public:
		/**
		 * @brief Get the player's piece.
		 */
		virtual EPiece GetPiece() const = 0;
		/**
		 * @brief Get the player's balance as a float.
		 */
		virtual float GetBalance() const = 0;
		/**
		 * @brief Set the player's balance.
		 */
		virtual void SetBalance(float newBalance) = 0;
		/**
		 * @brief Add some amount to the player's balance.
		 */
		virtual void ReceiveMoney(float amount) = 0;
		 /**
 		 * @brief Substract some amount from the player's balance.
 		 */
 		virtual void PayMoney(float amount) = 0;
		/**
		 * @brief Get the player's position on the board.
		 */
		virtual unsigned int GetPosition() const = 0;
		/**
		 * @brief Set the new position for the player.
		 */
		virtual void SetPosition(unsigned int position) = 0;
		virtual void SetPosition(ESquareType square) = 0;
		friend std::ostream& operator << (std::ostream& outputStream, const IPlayer& player);
	};
}

#endif
