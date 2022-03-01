// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "COwnershipCard.h"

using namespace std;
using namespace mp;

COwnershipCard::COwnershipCard(IOwnableSquare& property) : mProperty(property)
{
}

float COwnershipCard::GetCost() const
{
	return mProperty.GetCost();
}

float COwnershipCard::GetRent() const
{
	return mProperty.GetRent();
}

std::string COwnershipCard::GetName() const
{
		return mProperty.GetName();
}

bool COwnershipCard::IsMortgaged() const
{
	return mProperty.IsMortgaged();
}

void COwnershipCard::SetMortgaged(bool mortgaged) const
{
	mProperty.SetMortgaged(mortgaged);
}

namespace mp
{

	bool operator < (const COwnershipCard& a, const COwnershipCard& b)
	{
			return a.GetCost() < b.GetCost();
	}

	bool operator > (const COwnershipCard& a, const COwnershipCard& b)
	{
			return a.GetCost() > b.GetCost();
	}
}
