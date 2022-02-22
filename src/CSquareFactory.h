// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_SQUARE_FACTORY_H
#define MP_SQUARE_FACTORY_H

#include <string>
#include "CSquare.h"

namespace mp
{
	/**
	 * @brief Factory for objects that are of type or inherit CSquare.
	 */
	class CSquareFactory
	{
	public:
		static CSquare parseString(std::string propertyLine);
	};
}

#endif
