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
		CChanceSquare(std::string name, ESquareType type);
		virtual void PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, std::ostream& outputStream);
		virtual CChanceCard GetChanceCard(int index) = 0;
		virtual void AffectPlayer(IPlayer& player, CBank& bank, CChanceCard chanceCard, std::ostream& outputStream) = 0;
	protected:
		std::vector<CChanceCard> mChanceCards;
	};
}

#endif
