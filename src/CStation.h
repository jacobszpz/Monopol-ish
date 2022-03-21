// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_STATION_H
#define MP_STATION_H

#include "CProperty.h"
#include "IOwnableSquare.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents an ownable station.
	 */
	class CStation : public CProperty
	{
	public:
		/**
		 * @brief Represents a Station Square, a type of property.
		 */
		CStation(std::string name);
		/**
		 * @brief Display the message shown when player lands on an owned Station.
		 */
		virtual void DisplayRentMessage(std::ostream& outputStream, IPlayer& player) const;
	protected:
		static constexpr float STATION_COST = 200;
		static constexpr float STATION_RENT = 10;
	};
}

#endif
