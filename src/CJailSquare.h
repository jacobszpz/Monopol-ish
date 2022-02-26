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
	 * @brief Type of CSquare that represents an ownable property.
	 */
	class CJailSquare : public CSquare
	{
	public:
		CJailSquare(std::string name);
		virtual void PlayerLands(CPlayer& player, std::ostream& outputStream);
	protected:
	};
}

#endif
