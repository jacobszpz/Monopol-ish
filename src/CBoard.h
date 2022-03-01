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

namespace mp
{
	/**
	 * @brief Represents a Monopolish board.
	 */
	class CBoard
	{
	public:
		CBoard();
		CBoard(std::string setupFilename);
		unsigned int GetJailSquareIndex() const;
		unsigned int GetNumberOfSquares() const;
		CSquare& GetSquare(unsigned int n);
	protected:
		unsigned int mJailSquareIndex;
		int mGoToJailSquareIndex;
		BoardSquares mSquares;
	};
}

#endif
