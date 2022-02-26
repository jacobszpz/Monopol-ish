// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_MONOPOLISH_H
#define MP_MONOPOLISH_H

#include <vector>
#include <memory>
#include <iostream>
#include "CSquare.h"
#include "CPlayer.h"
#include "CSquareFactory.h"

namespace mp
{
	typedef std::vector<std::unique_ptr<CPlayer>> Players;

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
		CMonopolish(std::ostream& outputStream);
		void AddPlayer(EPiece playingPiece);
		void Play();
		void Round(int roundNo);
		void DisplayPlayerBalances();
    //void Round();
	protected:
		/// Number of rounds to play.
	  const unsigned int ROUNDS_NO = 20;
		const float GO_BONUS{200};
		const std::string BOARD_SETUP_FILENAME = "./src/monopolish.txt";

		std::ostream& mOutStream;
		Players mPlayers;
		BoardSquares mSquares;

	};
}

#endif
