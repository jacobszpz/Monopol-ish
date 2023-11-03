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
	 * @brief Type of CSquare that represents a Go To Jail square.
	 */
	class CGoToJailSquare : public CSquare
	{
	public:
		/// Create a Square to send any player to Jail
		CGoToJailSquare(std::string name);
		/// Sends the player who lands to the Jail Square, and charges a fee.
		virtual void PlayerLands(std::unique_ptr<IPlayer>& player, PlayerMap& players, std::unique_ptr<CBank>& bank, std::ostream& outputStream);
	protected:
		const float JAIL_PENALTY = 50;
	};
}

#endif
