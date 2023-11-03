// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_PENALTY_SQR_H
#define MP_PENALTY_SQR_H

#include <vector>
#include "CChanceSquare.h"
#include "CChanceCard.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents a bonus square.
	 */
	class CPenalty : public CChanceSquare
	{
	public:
		/**
		 * @brief Create a Penalty Square.
		 */
		CPenalty(std::string name);
		/**
		 * @brief Get a chance card at a certain index.
		 */
		virtual CChanceCard GetChanceCard(int index);
		/**
		 * @brief Takes the amount of the chance card from the player's balance.
		 */
		virtual void AffectPlayer(std::unique_ptr<IPlayer>& player, std::unique_ptr<CBank>& bank, CChanceCard chanceCard, std::ostream& outputStream);
	protected:
		/// Contain penalty chance cards
		std::vector<CChanceCard> mPenalties {
			{"Buy a coffee in Starbucks.", 20},
			{"Pay your broadband bill.", 50},
			{"Visit the SU shop for food.", 100},
			{"Buy an assignment solution.", 150},
			{"Go for a romantic meal.", 200},
			{"Pay some university fees.", 300}
		};
	};
}

#endif
