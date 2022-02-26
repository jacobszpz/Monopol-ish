// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_GO_JAIL_SQR_H
#define MP_GO_JAIL_SQR_H

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
	protected:
	};
}

#endif
