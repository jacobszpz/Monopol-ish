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


void CGoSquare::PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, ostream& outputStream)
{

}

void CGoSquare::PlayerPasses(IPlayer& player, PlayerMap& playerMap, CBank& bank, ostream& outputStream)
{
	outputStream << player << " passes GO and collects " << POUND << GO_BONUS << endl;
	player.Receive(bank.Withdraw(GO_BONUS));
}
