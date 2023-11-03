// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_SQUARE_H
#define MP_SQUARE_H

#include <map>
#include <string>
#include <memory>
#include <iostream>
#include "CBank.h"
#include "IPlayer.h"
#include "ESquareType.h"
#include "Constants.h"
#include "EColour.h"

namespace mp
{
	/**
	 * @brief Represents a square in the board.
	 */
	class CSquare
	{
	public:
		/**
		 * @brief Create a CSquare, with the chosen name, and type.
		 */
		CSquare(std::string name, ESquareType type);
		virtual ~CSquare();
		/**
		 * @brief Virtual method called when player lands on the Square.
		 * Effects will depend on the type of Square.
		 */
		virtual void PlayerLands(std::unique_ptr<IPlayer>& player, PlayerMap& playerMap, std::unique_ptr<CBank>& bank, std::ostream& outputStream);
		/**
		 * @brief Virtual method called when player passes over the Square.
		 * Only called when user passes over CGoSquare, but still polymorphic.
		 */
		virtual void PlayerPasses(std::unique_ptr<IPlayer>& player, PlayerMap& playerMap, std::unique_ptr<CBank>& bank, std::ostream& outputStream);
		// Returns the name of the Square.
		std::string GetName() const;
		// Returns the type of the Square.
		ESquareType GetType() const;

		virtual EColour GetColour() const;
	protected:
		/// Square name.
		const std::string mName;
		/// Square type. Currently only used for the initial setup, to know where the Jail is located.
		ESquareType mType;
	};

	std::ostream& operator << (std::ostream& outputStream, const CSquare square);
}

#endif
