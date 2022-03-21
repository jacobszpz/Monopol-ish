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
		CPenalty(std::string name);
		virtual CChanceCard GetChanceCard(int index);
		virtual void AffectPlayer(IPlayer& player, CBank& bank, CChanceCard chanceCard, std::ostream& outputStream);
	protected:
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
