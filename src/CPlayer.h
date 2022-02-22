// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_PLAYER_H
#define MP_PLAYER_H

#include <string>

namespace mp
{
	/**
	 * @brief Represents a player of the game.
	 */
	class CPlayer
	{
		enum class EPiece
		{
			hamster,
			pumpkin
		};
	protected:
		std::string mName;
		EPiece mPiece;
		unsigned int mPosition = 0;
		float mMoney = 1500;
	};
}

#endif
