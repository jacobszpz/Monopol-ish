// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */


#ifndef MP_MONOPOLISH_H
#define MP_MONOPOLISH_H

#include <vector>
#include "CSquare.h"
#include "CPlayer.h"

namespace mp
{
	/**
	 * @brief Monopol-ish game manager.
	 *
	 * > Manages a simplified version of the classic game Monopoly.
	 * > This is not an interactive game you can play, but rather
	 * > a simulation of two players taking turns over a set number
	 * > of rounds. Play is to be automated according to a sequence
	 * > of pseudo-random numbers - there is no artificial
	 * > intelligence, and no user input.
	 */
	class CMonopolish
	{
	public:
		CMonopolish();
    void Round();
	protected:
		/// Number of rounds to play.
	  const unsigned int mRounds = 20;
    std::vector<CPlayer> mPlayers;
	};
}

#endif
