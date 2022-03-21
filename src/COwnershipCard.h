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
	 * @brief Card that represents the ownership of a property.
	 * Simplifies keeping records of owned properties within a player instance.
	 * Also, modelled after its real life counterpart.
	 */
	class COwnershipCard
	{
	public:
		/**
		 * @brief Create an ownership card for a certain ownable property.
		 *
		 * @param insertionIndex Used to keep track of ordering within the card set.
		 */
		COwnershipCard(IOwnableSquare& property, unsigned int insertionIndex);
		/**
		 * @brief Get the rent for the property.
		 */
		float GetRent() const;
		/**
		 * @brief Get the cost of the property.
		 */
		float GetCost() const;
		/**
		 * @brief Consult if property is currently mortgaged.
		 */
		bool IsMortgaged() const;
		/**
		 * @brief Retrieve the property's name.
		 */
		std::string GetName() const;
		/**
		 * @brief Set the property morgaging status.
		 */
		void SetMortgaged(bool mortgaged) const;
		/**
		 * @brief Compares the cost and insertion order of properties.
		 */
		friend bool operator < (const COwnershipCard& a, const COwnershipCard& b);
		friend bool operator > (const COwnershipCard& a, const COwnershipCard& b);
	protected:
		IOwnableSquare& mProperty;
		unsigned int mInsertionIndex;
	};
}

#endif
