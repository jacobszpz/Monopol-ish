// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CProperty.h"

using namespace std;
using namespace mp;

CProperty::CProperty(std::string name, float cost, float rent, EColour colourGroup) : CSquare(name), mCost(cost), mRent(rent), mColour(colourGroup)
{
}


void CProperty::PlayerLands(CPlayer& player, ostream& outputStream)
{
}
