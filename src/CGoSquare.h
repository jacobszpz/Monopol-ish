// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_GO_SQR_H
#define MP_GO_SQR_H

#include <iostream>
#include "CSquare.h"

namespace mp
{
	/**
	 * @brief Type of CSquare that represents the starting square.
	 */
	class CGoSquare : public CSquare
	{
	public:
		CGoSquare(std::string name);
		/**
		 * @brief Nothing actually happens.
		 */
		virtual void PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, std::ostream& outputStream);
		/**
		 * @brief Player collects a bonus (GO_BONUS).
		 */
		virtual void PlayerPasses(IPlayer& player, PlayerMap& playerMap, CBank& bank, std::ostream& outputStream);
	protected:
		/// Player bonus when landing on this square.
		const float GO_BONUS{200};

	};
}

#endif
