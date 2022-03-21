// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CBonus.h"

using namespace std;
using namespace mp;

CBonus::CBonus(string name): CChanceSquare(name, ESquareType::Bonus)
{
}

CChanceCard CBonus::GetChanceCard(int index)
{
	return mBonuses.at(index);
}

void CBonus::AffectPlayer(IPlayer& player, CBank& bank, CChanceCard chanceCard, ostream& outputStream)
{
	player.Receive(bank.Withdraw(chanceCard.GetAmount()));
	outputStream << chanceCard.GetDescription() << " Gain £" << chanceCard.GetAmount() << endl;
}
