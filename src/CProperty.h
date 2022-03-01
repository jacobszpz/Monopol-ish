// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_PROPERTY_H
#define MP_PROPERTY_H

#include "CSquare.h"
#include "EPiece.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents an ownable property.
	 */
	class CProperty : public CSquare, public IOwnableSquare
	{
	public:
		enum class EColour
		{
			Red = 0,
			Grey = 1,
			Brown = 2,
			Orange = 3,
			Yellow = 4,
			Green = 5,
			Blue = 6,
			Purple = 7
		};

		CProperty(std::string name, float cost, float rent, EColour colourGroup);
		virtual void PlayerLands(IPlayer& player, PlayerMap& playerMap, CBank& bank, std::ostream& outputStream);

		virtual std::string GetName() const;
		virtual float GetCost() const;
		virtual float GetRent() const;
		virtual EPiece GetOwner() const;
		virtual bool IsMortgaged() const;
		virtual void SetMortgaged(bool mortaged);
		virtual void DisplayRentMessage(std::ostream& outputStream, IPlayer& player) const;
	protected:
		float mCost;
		float mRent;
		EColour mColour;
		EPiece mOwnedBy = EPiece::none;
		bool mMortaged = false;
	};
}

#endif
