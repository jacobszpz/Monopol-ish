// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CJailSquare.h"

using namespace std;
using namespace mp;

CJailSquare::CJailSquare(string name): CSquare(name, ESquareType::Jail)
{
}


void CJailSquare::PlayerLands(IPlayer& player, ostream& outputStream)
{
	outputStream << player << " is just visiting" << endl;
}
