// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_MONOPOLISH_H
#define MP_MONOPOLISH_H

#include <map>
#include <vector>
#include <memory>
#include <iostream>
#include "CSquare.h"
#include "CPlayer.h"
#include "CSquareFactory.h"
#include "CBank.h"
#include "CChanceCard.h"
#include "CBoard.h"

/**
 * @brief Namespace for the Monopolish game.
 */
namespace mp
{
	/**
	 * @brief Monopol-ish game manager.
	 *
	 * > Manages a simplified version of the classic game Monopoly.
	 * > This is not an interactive game you can play, but rather
	 * > a simulation of two/four players taking turns over a set number
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
		int Play();
	protected:
		void DisplayPlayerBalances();
		/**
		 * @brief Play a round of the game (a turn for every player).
		 */
		bool Round(int roundNo);
		/**
		 * @brief Play the player's turn.
		 */
		void Turn(std::unique_ptr<IPlayer>& player);
		/// Number of rounds to play.
	  const unsigned int ROUNDS_NO = 20;
		/// Bank reserve amount.
		const float BANK_INITIAL_RESERVES = 20000;
		/// Initial player balance.
		const float PLAYER_INITIAL_BONUS = 1500;
		/// Filename of board setup file.
		const std::string BOARD_SETUP_FILENAME = "./src/monopolish.txt";
		/// Filename of seed file.
		const std::string DIE_SEED_FILENAME = "./src/seed.txt";

		/// Holds the stream to output the game to.
		std::ostream& mOutStream;
		PlayerMap mPlayers;
		std::unique_ptr<CBoard> mBoard;
		std::unique_ptr<CBank> mBank;
	};
}

#endif
