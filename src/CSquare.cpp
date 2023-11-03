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

CSquare::~CSquare(){}

void CSquare::PlayerLands(unique_ptr<IPlayer>& player, PlayerMap& playerMap, unique_ptr<CBank>& bank, ostream& outputStream)
{
}

void CSquare::PlayerPasses(unique_ptr<IPlayer>& player, PlayerMap& playerMap, unique_ptr<CBank>& bank, ostream& outputStream)
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

EColour CSquare::GetColour() const
{
	return EColour::None;
}

ostream& mp::operator << (ostream& outputStream, const CSquare square)
{
		outputStream << square.GetName();
		return outputStream;
}
