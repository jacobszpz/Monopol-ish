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

		/**
		 * @brief Creates a property Square, with the specified parameters.
		 */
		CProperty(std::string name, float cost, float rent, EColour colourGroup);
		/**
		 * @brief Make user buy property if not already owned, otherwise pay rent over it.
		 */
		virtual void PlayerLands(IPlayer& player, PlayerMap& playerMap, CBank& bank, std::ostream& outputStream);
		/// Property name
		virtual std::string GetName() const;
		/// Property cost
		virtual float GetCost() const;
		/// Property rent
		virtual float GetRent() const;
		/// Get the piece which owns this property, or EPiece::none if nobody does
		virtual EPiece GetOwner() const;
		/// Whether property is currently mortgaged
		virtual bool IsMortgaged() const;
		/// Set property mortgage status
		virtual void SetMortgaged(bool mortaged);
		/// Display rent message
		virtual void DisplayRentMessage(std::ostream& outputStream, IPlayer& player, IPlayer& owner) const;
	protected:
		float mCost;
		float mRent;
		EColour mColour;
		EPiece mOwnedBy = EPiece::none;
		bool mMortaged = false;
	};
}

#endif
