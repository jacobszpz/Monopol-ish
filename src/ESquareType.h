// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_PROPERTY_TYPE_H
#define MP_PROPERTY_TYPE_H

#include <iostream>

namespace mp
{
	/**
	 * @brief All the possible Square types.
	 */
	enum class ESquareType
	{
		Property = 1,
		Start = 2,
		Station = 3,
		Bonus = 4,
		Penalty = 5,
		Jail = 6,
		GoToJail = 7,
		FreeParking = 8
	};
}

#endif
