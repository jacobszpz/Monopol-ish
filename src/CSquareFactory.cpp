// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
 // uncomment to disable assert()
 // #define NDEBUG
#include <cassert>
#include "CSquareFactory.h"
#include "CProperty.h"
#include "CJailSquare.h"
#include "CGoToJailSquare.h"
#include "CFreeParkingSquare.h"
#include "CTextFiles.h"
#include "ESquareType.h"

using namespace std;
using namespace mp;
using namespace jsan;

BoardSquares CSquareFactory::ReadFromFile(std::string filename)
{
	BoardSquares squares;
	auto fileLines = CTextFiles::GetLinesFromFile(filename);

	for (auto line : fileLines)
	{
		squares.push_back(ParseString(line));
	}

	return squares;
}

unique_ptr<CSquare> CSquareFactory::ParseString(string squareDefinition)
{
	auto squareElements = CTextFiles::Split(squareDefinition);
	string firstElement = squareElements.front();
	int firstNumber = stoi(firstElement);
 	auto squareType = static_cast<ESquareType>(firstNumber);
	string squareName = "";
	unique_ptr<CSquare> square;

	if (squareType == ESquareType::Property)
	{
		int colourElement = stoi(squareElements.back());
		CProperty::EColour colour = static_cast<CProperty::EColour>(colourElement);
		squareElements.pop_back();

		float rent = stof(squareElements.back());
		squareElements.pop_back();

		float cost = stof(squareElements.back());
		squareElements.pop_back();

		for( auto it = ++squareElements.begin(); it != squareElements.end(); ++it )
		{
			squareName += *it;
			squareName += " ";
		}

		squareName.pop_back();
		squareName = squareElements.back();
		square = make_unique<CProperty>(squareName, cost, rent, colour);
	}
	else
	{
		squareDefinition.substr(firstElement.length() + 1);

		switch (squareType) {
			// case ESquareType::Start:
			// 	break;
			// case ESquareType::BusStation:
			// 	break;
			// case ESquareType::Bonus:
			// 	break;
			// case ESquareType::Penalty:
			// 	break;
			case ESquareType::Jail:
				square = make_unique<CJailSquare>(squareName);
				break;
			case ESquareType::GoToJail:
				square = make_unique<CGoToJailSquare>(squareName);
				break;
			case ESquareType::FreeParking:
				square = make_unique<CFreeParkingSquare>(squareName);
				break;
			default:
				square = make_unique<CSquare>(squareName);
				break;
		}
	}

	return move(square);
}
