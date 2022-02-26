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
		CPlayer(EPiece playingPiece);
		EPiece GetPiece() const;
		float GetBalance() const;
	protected:
		const EPiece mPiece;
		std::string mName;
		unsigned int mPosition = 0;
		float mMoney = 1500;
	};

	std::ostream& operator << (std::ostream& outputStream, const CPlayer piece);
}

#endif
