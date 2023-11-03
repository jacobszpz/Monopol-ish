// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CFreeParking.h"

using namespace std;
using namespace mp;

CFreeParkingSquare::CFreeParkingSquare(string name): CSquare(name, ESquareType::FreeParking)
{
}


void CFreeParkingSquare::PlayerLands(unique_ptr<IPlayer>& player, PlayerMap& players, unique_ptr<CBank>& bank, ostream& outputStream)
{
	//'<Player>lands on Free Parking'
	outputStream << player->GetPiece() << " is resting" << endl;
}
