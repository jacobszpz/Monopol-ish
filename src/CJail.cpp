// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CJail.h"

using namespace std;
using namespace mp;

CJailSquare::CJailSquare(string name): CSquare(name, ESquareType::Jail)
{
}


void CJailSquare::PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, ostream& outputStream)
{
	outputStream << player << " is just visiting" << endl;
}
