// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include "EPiece.h"

using namespace std;
using namespace mp;

ostream& mp::operator << (ostream& outputStream, const EPiece piece)
{
		switch(piece)
		{
				case EPiece::hamster:
					outputStream << "Hamster";
					break;
				case EPiece::pumpkin:
					outputStream << "Pumpkin";
					break;
				default:
					outputStream.setstate(ios_base::failbit);
		}
		return outputStream;
}
