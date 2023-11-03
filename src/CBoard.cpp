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

		EColour squareColour = mSquares.back()->GetColour();

		// Save count of number of properties with a certain color
		if (mPropertyColours.count(squareColour) == 0)
		{
			mPropertyColours[squareColour] = 0;
		}

		mPropertyColours.at(squareColour) += 1;

		++i;
	}
}

unique_ptr<CSquare>& CBoard::GetSquare(unsigned int index)
{
	return mSquares.at(index);
}

unsigned int CBoard::GetJailSquareIndex() const
{
	return mJailSquareIndex;
}

unsigned int CBoard::GetGoSquareIndex() const
{
	return mGoSquareIndex;
}

unsigned int CBoard::GetNumberOfSquares() const
{
	return mSquares.size();
}

unsigned int CBoard::GetCountByColour(EColour colour)
{
	unsigned int count = 0;
	if (mPropertyColours.count(colour) == 1)
	{
		count = mPropertyColours.at(colour);
	}

	return count;
}
