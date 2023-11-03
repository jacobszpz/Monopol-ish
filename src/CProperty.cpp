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

CProperty::~CProperty() {}

void CProperty::PlayerLands(unique_ptr<IPlayer>& player, PlayerMap& players, unique_ptr<CBank>& bank, ostream& outputStream)
{
	// Not owned
	if (mOwnedBy == EPiece::none)
	{
		if (player->GetBalance() > 0)
		{
			mOwnedBy = player->GetPiece();
			bank->Deposit(player->Pay(GetCost()));
			player->Own(*this);

			outputStream << player->GetPiece() << " buys " << this->GetName() << " for " << POUND << GetCost() << endl;
		}
	}
	// Already owned
	else if (mOwnedBy != player->GetPiece() && !mMortaged)
	{
		auto rent = GetRent();
		unique_ptr<IPlayer>& owner = players.at(mOwnedBy);
		bool hasAllColour = owner->HasAllOfColour(GetColour());

		// Check if owner has all of this colour
		if (hasAllColour)
		{
			rent *= mColourRentMultiplier;
		}

		owner->Receive(player->Pay(rent));
		DisplayRentMessage(outputStream, player, owner, hasAllColour);
	}
}

string CProperty::GetName() const
{
	return mName;
}

float CProperty::GetCost() const
{
	return mCost;
}

float CProperty::GetRent() const
{
	return mRent;
}

EColour CProperty::GetColour() const
{
	return mColour;
}

EPiece CProperty::GetOwner() const
{
	return mOwnedBy;
}

bool CProperty::IsMortgaged() const
{
	return mMortaged;
}

void CProperty::SetMortgaged(bool mortaged)
{
	mMortaged = mortaged;
}

bool CProperty::CanBeMortgaged() const
{
	return true;
}

void CProperty::DisplayRentMessage(std::ostream& outputStream, unique_ptr<IPlayer>& player, unique_ptr<IPlayer>& owner, bool hasAllColour) const
{
	auto rent = GetRent();
	if (hasAllColour)
	{
		rent *= mColourRentMultiplier;
	}
	outputStream << player->GetPiece() << " pays " << POUND << rent << " to " << owner->GetPiece() << endl;
}
