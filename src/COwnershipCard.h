// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_OWNERSHIP_CARD_H
#define MP_OWNERSHIP_CARD_H

#include <string>
#include "IOwnableSquare.h"
#include "EPiece.h"

namespace mp
{
	/**
	 * @brief Card that certifies the ownership of a property.
	 */
	class COwnershipCard
	{
	public:
		COwnershipCard(IOwnableSquare& property);
		float GetRent() const;
		float GetCost() const;
		bool IsMortgaged() const;
		std::string GetName() const;
		void SetMortgaged(bool mortgaged) const;
		friend bool operator < (const COwnershipCard& a, const COwnershipCard& b);
		friend bool operator > (const COwnershipCard& a, const COwnershipCard& b);
	protected:
		IOwnableSquare& mProperty;
	};
}

#endif
