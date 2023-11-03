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


void CJailSquare::PlayerLands(unique_ptr<IPlayer>& player, PlayerMap& players, unique_ptr<CBank>& bank, ostream& outputStream)
{
	outputStream << player->GetPiece() << " is just visiting" << endl;
}
