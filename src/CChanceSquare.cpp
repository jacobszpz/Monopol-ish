// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CChanceSquare.h"
#include "CDie.h"

using namespace std;
using namespace mp;

CChanceSquare::CChanceSquare(string name, ESquareType type): CSquare(name, type)
{
}


void CChanceSquare::PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, ostream& outputStream)
{
	unsigned int dieRoll{player.ThrowDie(outputStream)};
	auto chanceCard = GetChanceCard(dieRoll - 1);
	AffectPlayer(player, bank, chanceCard, outputStream);
}
