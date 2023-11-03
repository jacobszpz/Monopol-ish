// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CStation.h"

using namespace std;
using namespace mp;

CStation::CStation(string name): CProperty(name, STATION_COST, STATION_RENT, EColour::Station)
{
}

void CStation::DisplayRentMessage(std::ostream& outputStream, unique_ptr<IPlayer>& player, unique_ptr<IPlayer>& owner, bool hasAllColour) const
{
	outputStream << player->GetPiece() << " pays " << POUND << GetRent() <<  " to " << owner->GetPiece() <<  " for ticket" << endl;
}

bool CStation::CanBeMortgaged() const
{
	return false;
}
