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
#include "CGoSquare.h"
#include "CStation.h"
#include "CJailSquare.h"
#include "CGoToJailSquare.h"
#include "CFreeParkingSquare.h"
#include "CTextFiles.h"
#include "ESquareType.h"

using namespace std;
using namespace mp;
using namespace jsan;

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

		square = make_unique<CProperty>(squareName, cost, rent, colour);
	}
	else
	{
		squareName = squareDefinition.substr(firstElement.length() + 1);

		switch (squareType) {
			case ESquareType::Start:
				square = make_unique<CGoSquare>(squareName);
			 	break;
			// case ESquareType::Station:
			// 	square = make_unique<CStation>(squareName);
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
				square = make_unique<CSquare>(squareName, ESquareType::Start);
				break;
		}
	}

	return move(square);
}
