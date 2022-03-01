// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CProperty.h"

using namespace std;
using namespace mp;

CProperty::CProperty(std::string name, float cost, float rent, EColour colourGroup) : CSquare(name, ESquareType::Property), mCost(cost), mRent(rent), mColour(colourGroup)
{
}


void CProperty::PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, ostream& outputStream)
{
	if (mOwnedBy == EPiece::none)
	{
		if (player.GetBalance() > 0)
		{
			mOwnedBy = player.GetPiece();
			bank.Deposit(player.Pay(mCost));

			outputStream << player << " buys " << *this << " for " << mCost << endl;

		}
	}
	else if (mOwnedBy != player.GetPiece())
	{
		players.at(mOwnedBy)->Receive(player.Pay(mRent));
		outputStream << player << " pays " << mRent << endl;
	}
}
