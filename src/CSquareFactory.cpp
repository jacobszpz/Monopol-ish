// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

 #include <iostream>
 // uncomment to disable assert()
 // #define NDEBUG
#include <cassert>
#include "CSquareFactory.h"
#include "CTextFiles.h"

using namespace std;
using namespace mp;
using namespace jsan;

BoardSquares CSquareFactory::ReadFromFile(std::string filename)
{
	BoardSquares squares;
	auto fileLines = CTextFiles::GetLinesFromFile(filename);

	for (auto line : fileLines)
	{
		squares.push_back(make_unique<CSquare>(ParseString(line)));
	}

	return squares;
}

CSquare CSquareFactory::ParseString(string squareDefinition)
{
	string squareDescription = squareDefinition.substr(SQUARE_NAME_START);
	string firstElement = squareDefinition.substr(0, SQUARE_NAME_START - 1);
	int firstNumber = stoi(firstElement);
 	auto squareType = static_cast<EPropertyType>(firstNumber);

	switch (squareType) {
		case EPropertyType::Property:
			break;
		case EPropertyType::Start:
			break;
		case EPropertyType::BusStation:
			break;
		case EPropertyType::Bonus:
			break;
		case EPropertyType::Penalty:
			break;
		case EPropertyType::Jail:
			break;
		case EPropertyType::GoToJail:
			break;
		case EPropertyType::FreeParking:
			break;
		default:
			break;
	}

	return CSquare("");
}
