// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_PLAYER_H
#define MP_PLAYER_H

#include <string>
#include "EPiece.h"

namespace mp
{
	/**
	 * @brief Represents a player of the game.
	 */
	class CPlayer
	{
	public:
		/**
		 * @brief Create a player with the specified playing piece.
		 */
		CPlayer(EPiece playingPiece);
		/**
		 * @brief Get the player's piece.
		 */
		EPiece GetPiece() const;
		/**
		 * @brief Get the player's balance as a float.
		 */
		float GetBalance() const;
		void DisplayBalance(std::ostream& outputStream) const;
	protected:
		const EPiece mPiece;
		std::string mName;
		/// Player's position on the board
		unsigned int mPosition = 0;
		float mMoney = 1500;
	};

	std::ostream& operator << (std::ostream& outputStream, const CPlayer piece);
}

#endif
