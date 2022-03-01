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
		 * @brief Get the player's position on the board.
		 */
		virtual unsigned int GetPosition() const = 0;
		/**
		 * @brief Set the new position for the player.
		 */
		virtual void SetPosition(unsigned int position) = 0;
		virtual void SetPosition(ESquareType square) = 0;
		virtual void DisplayBalance(std::ostream& outputStream) const = 0;
		friend std::ostream& operator << (std::ostream& outputStream, const IPlayer& player);
	};

	typedef std::map<EPiece, std::unique_ptr<IPlayer>> PlayerMap;
}

#endif
