// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "COwnershipCard.h"

using namespace std;
using namespace mp;

COwnershipCard::COwnershipCard(IOwnableSquare& property, unsigned int insertionIndex) : mProperty(property), mInsertionIndex(insertionIndex)
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

bool COwnershipCard::CanBeMortgaged() const
{
	return mProperty.CanBeMortgaged();
}

namespace mp
{

	bool operator < (const unique_ptr<COwnershipCard>& a, const unique_ptr<COwnershipCard>& b)
	{
		return (a->GetCost() < b->GetCost()) || (a->GetCost() == b->GetCost() && a->mInsertionIndex < b->mInsertionIndex);
	}

	bool operator > (const unique_ptr<COwnershipCard>& a, const unique_ptr<COwnershipCard>& b)
	{
			return (a->GetCost() > b->GetCost()) || (a->GetCost() == b->GetCost() && a->mInsertionIndex > b->mInsertionIndex);
	}
}
