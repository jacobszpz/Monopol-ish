// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <string>
#include "CSquare.h"

using namespace std;
using namespace mp;


CSquare::CSquare(string name, ESquareType type) : mName(name), mType(type)
{
}

void CSquare::PlayerLands(IPlayer& player, PlayerMap& playerMap, CBank& bank, ostream& outputStream)
{
}

void CSquare::PlayerPasses(IPlayer& player, PlayerMap& playerMap, CBank& bank, ostream& outputStream)
{
}

string CSquare::GetName() const
{
	return mName;
}

ESquareType CSquare::GetType() const
{
	return mType;
}

ostream& mp::operator << (ostream& outputStream, const CSquare square)
{
		outputStream << square.GetName();
		return outputStream;
}
