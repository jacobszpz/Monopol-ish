// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#ifndef MP_SQUARE_FACTORY_H
#define MP_SQUARE_FACTORY_H

#include <string>
#include <vector>
#include <memory>
#include "CSquare.h"

namespace mp
{
	typedef std::vector<std::unique_ptr<CSquare>> BoardSquares;

	/**
	 * @brief Factory for objects that are of type or inherit CSquare.
	 */
	class CSquareFactory
	{
	public:
		static CSquare ParseString(std::string squareDefinition);
		static std::vector<std::unique_ptr<CSquare>> ReadFromFile(std::string filename);
	protected:
		static constexpr int SQUARE_NAME_START = 2;
	};
}

#endif
