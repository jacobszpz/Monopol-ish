// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <memory>
#include "CMonopolish.h"

using namespace mp;

int main()
{
	// Create game
	std::unique_ptr<CMonopolish> monopolishGame{std::make_unique<CMonopolish>()};

	// Add players
	monopolishGame->AddPlayer(EPiece::hamster);
	monopolishGame->AddPlayer(EPiece::pumpkin);
	//monopolishGame->AddPlayer(EPiece::dog);
	//monopolishGame->AddPlayer(EPiece::jaguar);

	// Play game
	return monopolishGame->Play();
}
