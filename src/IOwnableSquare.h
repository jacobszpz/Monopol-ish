// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_I_OWNABLE_SQR_H
#define MP_I_OWNABLE_SQR_H

#include <string>
#include "EPiece.h"

namespace mp
{
	/**
	 * @brief Interface for CSquares that represent an ownable property.
	 */
	class IOwnableSquare
	{
	public:
		virtual std::string GetName() const = 0;
		virtual float GetCost() const = 0;
		virtual float GetRent() const = 0;
		virtual EPiece GetOwner() const = 0;
		virtual bool IsMortgaged() const = 0;
		virtual void SetMortgaged(bool mortaged) = 0;
	};
}

#endif
