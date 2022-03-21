// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_I_PLAYER_H
#define MP_I_PLAYER_H

#include <map>
#include <string>
#include <memory>
#include "EPiece.h"
#include "CBank.h"
#include "IOwnableSquare.h"
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
		virtual void Receive(float amount) = 0;
		/**
 		 * @brief Substract some amount from the player's balance.
 		 */
		virtual float Pay(float amount) = 0;
		/**
		 * @brief Register a property under the player's ownership.
		 */
		virtual void Own(IOwnableSquare& ownedSquare) = 0;
		/**
		 * @brief Check player's balance after their turn.
		 */
		virtual void BalanceCheck(std::ostream& outputStream, CBank bank) = 0;
		/**
		 * @brief Whether the player has become bankrupt.
		 */
		virtual bool IsBankrupt() = 0;
		/**
		 * @brief Get the player's position on the board.
		 */
		virtual unsigned int GetPosition() const = 0;
		/**
		 * @brief Set the new position for the player.
		 */
		virtual void SetPosition(unsigned int position) = 0;
		/**
		 * @brief Set the new position to a special type of square.
		 */
		virtual void SetPosition(ESquareType square) = 0;
		/**
		 * @brief Print the player's balance through an std::ostream.
		 */
		virtual void DisplayBalance(std::ostream& outputStream) const = 0;
		/**
		 * @brief Throws die
		 */
		virtual unsigned int ThrowDie(std::ostream& outputStream) const = 0;

		friend std::ostream& operator << (std::ostream& outputStream, const IPlayer& player);
	};

	typedef std::map<EPiece, std::unique_ptr<IPlayer>> PlayerMap;
	typedef std::pair<EPiece, std::unique_ptr<IPlayer>> PlayerByPiece;
}

#endif
