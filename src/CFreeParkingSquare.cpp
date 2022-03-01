// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CFreeParkingSquare.h"

using namespace std;
using namespace mp;

CFreeParkingSquare::CFreeParkingSquare(string name): CSquare(name, ESquareType::FreeParking)
{
}


void CFreeParkingSquare::PlayerLands(IPlayer& player, PlayerMap& players, CBank& bank, ostream& outputStream)
{
	//'<Player>lands on Free Parking'
	outputStream << player << " is resting" << endl;
}
