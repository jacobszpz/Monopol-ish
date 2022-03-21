// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include "IPlayer.h"

using namespace std;
using namespace mp;

namespace mp {
	ostream& operator << (ostream& outputStream, const IPlayer& player)
	{
		// Output piece name
		outputStream << player.GetPiece();
		return outputStream;
	}
}
