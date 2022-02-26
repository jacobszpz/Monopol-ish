// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include <memory>
#include "CMonopolish.h"
#include "CSquareFactory.h"
#include "EPiece.h"

using namespace std;
using namespace mp;

int main()
{
	unique_ptr<CMonopolish> monopolishGame = make_unique<CMonopolish>();
	monopolishGame->AddPlayer(EPiece::hamster);
	monopolishGame->AddPlayer(EPiece::pumpkin);

	monopolishGame->Play();
	return 0;
}
