// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_PLAYER_H
#define MP_PLAYER_H

#include <string>
#include <set>
#include "IPlayer.h"
#include "EPiece.h"
#include "CBank.h"
#include "CBoard.h"
#include "ESquareType.h"
#include "COwnershipCard.h"

namespace mp
{
	/**
	 * @brief Represents a player of the game.
	 */
	class CPlayer : public IPlayer
	{
	public:
		/**
		 * @brief Create a player.
		 * @param playingPiece The player's token.
		 * @param bank The game's bank.
		 */
		CPlayer(EPiece playingPiece, CBoard& board);
		/**
		 * @brief Get the player's piece.
		 */
		virtual EPiece GetPiece() const;
		/**
		 * @brief Get the player's balance as a float.
		 */
		virtual float GetBalance() const;
		/**
		 * @brief Set the player's balance.
		 */
		virtual void SetBalance(float newBalance);
		/**
		 * @brief Add some amount to the player's balance.
		 */
		virtual void Receive(float amount);
		/**
 		 * @brief Substract some amount from the player's balance.
 		 */
		virtual float Pay(float amount);
		/**
		 * @brief Register a property under the player's ownership.
		 */
		virtual void Own(IOwnableSquare& ownedSquare);
		/**
		 * @brief Check player's balance after their turn.
		 */
		virtual void BalanceCheck(std::ostream& outputStream, CBank bank);
		/**
		 * @brief Whether player has become bankrupt.
		 */
		virtual bool IsBankrupt();
		/**
		 * @brief Get the player's position on the board.
		 */
		virtual unsigned int GetPosition() const;
		/**
		 * @brief Set the new position for the player.
		 */
		virtual void SetPosition(unsigned int position);
		/**
		 * @brief Set the new position to a special type of square.
		 */
		virtual void SetPosition(ESquareType square);
		/**
		 * @brief Print the player's balance through an `std::ostream`.
		 */
		void DisplayBalance(std::ostream& outputStream) const;
	protected:
		const EPiece mPiece;
		/// Player's position on the board
		unsigned int mPosition = 0;
		float mMoney = 0;
		CBoard& mBoard;
		std::set<COwnershipCard> mProperties;
		bool mBankrupt = false;
	};

	//std::ostream& operator << (std::ostream& outputStream, const CPlayer piece);
}

#endif
