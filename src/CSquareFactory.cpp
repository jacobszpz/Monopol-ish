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
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"
#include "CBonus.h"
#include "CPenalty.h"
#include "CTextFiles.h"
#include "ESquareType.h"

using namespace std;
using namespace mp;
using namespace jsan;

unique_ptr<CSquare> CSquareFactory::ParseString(string squareDefinition)
{
	// Split string into parts
	auto squareElements = CTextFiles::Split(squareDefinition);
	// Get square type
	string firstElement = squareElements.front();
	int firstNumber = stoi(firstElement);
 	auto squareType = static_cast<ESquareType>(firstNumber);

	string squareName = "";
	// Declare ptr
	unique_ptr<CSquare> square;

	// Do additional processing for a property square
	if (squareType == ESquareType::Property)
	{
		int colourElement = stoi(squareElements.back());
		EColour colour = static_cast<EColour>(colourElement);
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
		// Create other types of square
		squareName = squareDefinition.substr(firstElement.length() + 1);
		squareName = CTextFiles::Strip(squareName);

		switch (squareType) {
			case ESquareType::Start:
				square = make_unique<CGoSquare>(squareName);
			 	break;
			case ESquareType::Station:
				square = make_unique<CStation>(squareName);
				break;
			case ESquareType::Bonus:
				square = make_unique<CBonus>(squareName);
				break;
			case ESquareType::Penalty:
				square = make_unique<CPenalty>(squareName);
				break;
			case ESquareType::Jail:
				square = make_unique<CJailSquare>(squareName);
				break;
			case ESquareType::GoToJail:
				square = make_unique<CGoToJailSquare>(squareName);
				break;
			case ESquareType::FreeParking:
				square = make_unique<CFreeParkingSquare>(squareName);
				break;
			case ESquareType::Property:
				break;
		}
	}

	return move(square);
}
