// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_JAIL_SQR_H
#define MP_JAIL_SQR_H

#include "CSquare.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents the Jail square.
	 */
	class CJailSquare : public CSquare
	{
	public:
		/// Create a Jail Square
		CJailSquare(std::string name);
		/// Has no effect on the player, only displays a message
		virtual void PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, std::ostream& outputStream);
	protected:
	};
}

#endif
