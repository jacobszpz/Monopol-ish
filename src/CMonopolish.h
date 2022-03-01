// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_MONOPOLISH_H
#define MP_MONOPOLISH_H

#include <set>
#include <vector>
#include <memory>
#include <iostream>
#include "CSquare.h"
#include "CPlayer.h"
#include "CSquareFactory.h"
#include "CBank.h"
#include "CChanceCard.h"
#include "CBoard.h"

namespace mp
{
	typedef std::vector<std::unique_ptr<CPlayer>> Players;
	typedef std::set<EPiece> GamePieces;

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
		/**
		 * @brief Create a Monopolish game that outputs to `std::cout`.
		 */
		CMonopolish();
		/**
		 * @brief Create a Monopolish game that outputs to a custom `std::ostream`.
		 */
		CMonopolish(std::ostream& outputStream);
		/**
		 * @brief Add a player to the game.
		 * @param playingPiece The player's piece of choice.
		 * @returns True if piece has not been taken, otherwise false.
		 */
		bool AddPlayer(EPiece playingPiece);
		/**
		 * @brief Plays the game.
		 */
		void Play();
	protected:
		void DisplayPlayerBalances();
		/**
		 * @brief Simulates a round of the game (a turn for every player).
		 */
		void Round(int roundNo);
		void Turn(const std::unique_ptr<CPlayer>& player);
		/// Number of rounds to play.
	  const unsigned int ROUNDS_NO = 20;
		/// Bank reserve amount
		const float BANK_INITIAL_RESERVES = 20000;
		/// Initial player balance
		const float PLAYER_INITIAL_BONUS = 1500;
		/// Filename of board setup file.
		const std::string BOARD_SETUP_FILENAME = "./src/monopolish.txt";

		std::vector<CChanceCard> mBonuses {
			{"Find some money.", 20},
			{"Win a coding competition.", 50},
			{"Receive a rent rebate.", 100},
			{"Win the lottery.", 150},
			{"Sell your iPad.", 200},
			{"It’s your birthday.", 300}
		};

		std::vector<CChanceCard> mPenalties {
			{"Buy a coffee in Starbucks.", 20},
			{"Pay your broadband bill.", 50},
			{"Visit the SU shop for food.", 100},
			{"Buy an assignment solution.", 150},
			{"Go for a romantic meal.", 200},
			{"Pay some university fees.", 300}
		};

		/// Holds the stream to output the game to.
		std::ostream& mOutStream;
		Players mPlayers;
		std::unique_ptr<CBoard> mBoard;
		GamePieces mPieces;
		std::unique_ptr<CBank> mBank;
	};
}

#endif
