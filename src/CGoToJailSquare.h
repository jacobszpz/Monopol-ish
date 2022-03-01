// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_GO_JAIL_SQR_H
#define MP_GO_JAIL_SQR_H

#include <iostream>
#include "CSquare.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents an ownable property.
	 */
	class CGoToJailSquare : public CSquare
	{
	public:
		CGoToJailSquare(std::string name);
		virtual void PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, std::ostream& outputStream);
	protected:
		const float JAIL_PENALTY = 50;
	};
}

#endif
