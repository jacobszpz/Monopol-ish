// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CPenalty.h"

using namespace std;
using namespace mp;

CPenalty::CPenalty(string name): CChanceSquare(name, ESquareType::Penalty)
{
}

CChanceCard CPenalty::GetChanceCard(int index)
{
	return mPenalties.at(index);
}

void CPenalty::AffectPlayer(unique_ptr<IPlayer>& player, unique_ptr<CBank>& bank, CChanceCard chanceCard, ostream& outputStream)
{
	bank->Deposit(player->Pay(chanceCard.GetAmount()));
	outputStream << chanceCard.GetDescription() << " Lose " << POUND << chanceCard.GetAmount() << endl;
}
