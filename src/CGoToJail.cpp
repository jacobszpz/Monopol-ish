// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CGoToJail.h"

using namespace std;
using namespace mp;

CGoToJailSquare::CGoToJailSquare(string name): CSquare(name, ESquareType::GoToJail)
{
}


void CGoToJailSquare::PlayerLands(unique_ptr<IPlayer>& player, PlayerMap& players, unique_ptr<CBank>& bank, ostream& outputStream)
{
	outputStream << player->GetPiece() << " goes to Jail" << endl;
	outputStream << player->GetPiece() << " pays " << POUND << JAIL_PENALTY << endl;
	bank->Deposit(player->Pay(JAIL_PENALTY));
	player->SetPosition(ESquareType::Jail);
}
