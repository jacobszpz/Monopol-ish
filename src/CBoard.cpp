// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <string>
#include "CBoard.h"
#include "CTextFiles.h"

using namespace std;
using namespace mp;
using namespace jsan;


CBoard::CBoard()
{
}

CBoard::CBoard(string setupFilename)
{
	auto fileLines = CTextFiles::GetLinesFromFile(setupFilename);
	int i = 0;

	for (auto line : fileLines)
	{
		mSquares.push_back(CSquareFactory::ParseString(line));
		ESquareType squareType = mSquares.back()->GetType();

		// Save index of Jail square
		if (squareType == ESquareType::Jail)
		{
			mJailSquareIndex = i;
		}

		++i;
	}
}

CSquare& CBoard::GetSquare(unsigned int n)
{
	return *(mSquares.at(n));
}

unsigned int CBoard::GetJailSquareIndex() const
{
	return mJailSquareIndex;
}

unsigned int CBoard::GetNumberOfSquares() const
{
	return mSquares.size();
}
