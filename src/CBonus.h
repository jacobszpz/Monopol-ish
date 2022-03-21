// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_BONUS_SQR_H
#define MP_BONUS_SQR_H

#include <vector>
#include "CChanceSquare.h"
#include "CChanceCard.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents a bonus square.
	 */
	class CBonus : public CChanceSquare
	{
	public:
		/**
		 * @brief Create a bonus square.
		 */
		CBonus(std::string name);
		/**
		 * @brief Get a chance card by index.
		 */
		virtual CChanceCard GetChanceCard(int index);
		/**
		 * @brief Add the card's amount to the player's pocket.
		 */
		virtual void AffectPlayer(IPlayer& player, CBank& bank, CChanceCard chanceCard, std::ostream& outputStream);
	protected:
		/// Contains bonus cards.
		std::vector<CChanceCard> mBonuses {
			{"Find some money.", 20},
			{"Win a coding competition.", 50},
			{"Receive a rent rebate.", 100},
			{"Win the lottery.", 150},
			{"Sell your iPad.", 200},
			{"It’s your birthday.", 300}
		};
	};
}

#endif
