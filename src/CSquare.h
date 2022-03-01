// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_SQUARE_H
#define MP_SQUARE_H

#include <string>
#include <iostream>
#include "IPlayer.h"
#include "ESquareType.h"

namespace mp
{
	/**
	 * @brief Represents a square in the board.
	 */
	class CSquare
	{
	public:
		CSquare(std::string name, ESquareType type);
		virtual void PlayerLands(IPlayer& player, std::ostream& outputStream);
		std::string GetName() const;
		ESquareType GetType() const;
	protected:
		const std::string mName;
		ESquareType mType;
	};

	std::ostream& operator << (std::ostream& outputStream, const CSquare square);
}

#endif
