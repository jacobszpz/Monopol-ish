// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_CHANCE_SQR_H
#define MP_CHANCE_SQR_H

#include <vector>
#include "CSquare.h"
#include "CChanceCard.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents a chance square.
	 */
	class CChanceSquare : public CSquare
	{
	public:
		/**
		 * @brief Create a square that's either a Bonus or Penalty.
		 */
		CChanceSquare(std::string name, ESquareType type);
		/**
		 * @brief Roll the die and affect the player with a random chance card.
		 */
		virtual void PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, std::ostream& outputStream);
		/**
		 * @brief Retrieve a chance card by index.
		 */
		virtual CChanceCard GetChanceCard(int index) = 0;
		/**
		 * @brief Affect the player's balance based on the chance card provided.
		 */
		virtual void AffectPlayer(IPlayer& player, CBank& bank, CChanceCard chanceCard, std::ostream& outputStream) = 0;
	};
}

#endif
