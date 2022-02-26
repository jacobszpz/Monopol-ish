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
	 * @brief Type of CSquare that represents an ownable property.
	 */
	class CFreeParkingSquare : public CSquare
	{
	public:
		CFreeParkingSquare(std::string name);
	protected:
	};
}

#endif
