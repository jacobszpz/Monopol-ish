// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_SQUARE_H
#define MP_SQUARE_H

#include <string>
#include <iostream>
#include "CPlayer.h"
#include "ESquareType.h"

namespace mp
{
	/**
	 * @brief Represents a square in the board.
	 */
	class CSquare
	{
	public:
		CSquare(std::string name);
		virtual void PlayerLands(CPlayer& player, std::ostream& outputStream);
	protected:
		std::string mName;
		ESquareType mType;

	};
}

#endif
