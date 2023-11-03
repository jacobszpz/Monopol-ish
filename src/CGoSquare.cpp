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


void CGoSquare::PlayerLands(unique_ptr<IPlayer>& player, PlayerMap& players, unique_ptr<CBank>& bank, ostream& outputStream)
{

}

void CGoSquare::PlayerPasses(unique_ptr<IPlayer>& player, PlayerMap& playerMap, unique_ptr<CBank>& bank, ostream& outputStream)
{
	outputStream << player->GetPiece() << " passes GO and collects " << POUND << GO_BONUS << endl;
	player->Receive(bank->Withdraw(GO_BONUS));
}
