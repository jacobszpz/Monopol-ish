// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_BOARD_H
#define MP_BOARD_H

#include <string>
#include <vector>
#include <memory>
#include "CSquare.h"
#include "CSquareFactory.h"
#include "EColour.h"

namespace mp
{
	/**
	 * @brief Represents a Monopolish board.
	 */
	class CBoard
	{
	public:
		CBoard();
		/**
		 * @brief Load a board from the specified setup file.
		 */
		CBoard(std::string setupFilename);
		/**
		 * @brief Get the index of the Jail Square.
		 */
		unsigned int GetJailSquareIndex() const;
		/**
		 * @brief Get the index of the Go Square.
		 */
		unsigned int GetGoSquareIndex() const;
		/**
		 * @brief Get the number of squares in the board.
		 */
		unsigned int GetNumberOfSquares() const;
		/**
		 * @brief Get a reference to a Square on the board.
		 */
		std::unique_ptr<CSquare>& GetSquare(unsigned int index);
		/**
		 * @brief Get property count for a certain colour
		 */
		 unsigned int GetCountByColour(EColour colour);
	protected:
		unsigned int mJailSquareIndex;
		BoardSquares mSquares;
		const unsigned int mGoSquareIndex = 0;
		std::map<EColour, unsigned int> mPropertyColours;
	};
}

#endif
