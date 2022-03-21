// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CStation.h"

using namespace std;
using namespace mp;

CStation::CStation(string name): CProperty(name, STATION_COST, STATION_RENT, EColour::Red)
{
}

void CStation::DisplayRentMessage(std::ostream& outputStream, IPlayer& player) const
{
	outputStream << player << " pays " << POUND << GetRent() <<  " for ticket" << endl;
}
