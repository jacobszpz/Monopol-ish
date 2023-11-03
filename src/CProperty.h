// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_PROPERTY_H
#define MP_PROPERTY_H

#include "CSquare.h"
#include "EPiece.h"
#include "EColour.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents an ownable property.
	 */
	class CProperty : public CSquare, public IOwnableSquare
	{
	public:
		/**
		 * @brief Creates a property Square, with the specified parameters.
		 */
		CProperty(std::string name, float cost, float rent, EColour colourGroup);
		virtual ~CProperty();
		/**
		 * @brief Make user buy property if not already owned, otherwise pay rent over it.
		 */
		virtual void PlayerLands(std::unique_ptr<IPlayer>& player, PlayerMap& playerMap, std::unique_ptr<CBank>& bank, std::ostream& outputStream);
		/// Property name
		virtual std::string GetName() const;
		/// Property cost
		virtual float GetCost() const;
		/// Property rent
		virtual float GetRent() const;
		/// Property colour
		virtual EColour GetColour() const;
		/// Get the piece which owns this property, or EPiece::none if nobody does
		virtual EPiece GetOwner() const;
		/// Whether property is currently mortgaged
		virtual bool IsMortgaged() const;
		/// Set property mortgage status
		virtual void SetMortgaged(bool mortaged);
		virtual bool CanBeMortgaged() const;
		/// Display rent message
		virtual void DisplayRentMessage(std::ostream& outputStream, std::unique_ptr<IPlayer>& player, std::unique_ptr<IPlayer>& owner, bool hasAllColour) const;
	protected:
		float mCost;
		float mRent;
		EColour mColour;
		EPiece mOwnedBy = EPiece::none;
		bool mMortaged = false;
		const int mColourRentMultiplier = 2;
	};
}

#endif
