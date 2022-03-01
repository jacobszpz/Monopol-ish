// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CGoSquare.h"

using namespace std;
using namespace mp;

CGoSquare::CGoSquare(string name): CSquare(name, ESquareType::Start)
{
}


void CGoSquare::PlayerLands(IPlayer& player, ostream& outputStream)
{
	outputStream << player << " passes GO and collects £" << GO_BONUS << endl;
	player.ReceiveMoney(GO_BONUS);
}
