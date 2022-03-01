// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_GO_SQR_H
#define MP_GO_SQR_H

#include <iostream>
#include "CSquare.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents an ownable property.
	 */
	class CGoSquare : public CSquare
	{
	public:
		CGoSquare(std::string name);
		virtual void PlayerLands(IPlayer& player, std::ostream& outputStream);
	protected:
		/// Player bonus when landing on this square.
		const float GO_BONUS{200};

	};
}

#endif
