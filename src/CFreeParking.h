// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_FREE_PARKING_SQR_H
#define MP_FREE_PARKING_SQR_H

#include "CSquare.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents a Free Parking square.
	 */
	class CFreeParkingSquare : public CSquare
	{
	public:
		/// Create a Free Parking Square
		CFreeParkingSquare(std::string name);
		/// Only display a message, no other effects
		virtual void PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, std::ostream& outputStream);
	protected:
	};
}

#endif
