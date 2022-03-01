// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <memory>
#include "CMonopolish.h"

using namespace mp;

int main()
{
	std::unique_ptr<CMonopolish> monopolishGame{std::make_unique<CMonopolish>()};
	monopolishGame->AddPlayer(EPiece::hamster);
	monopolishGame->AddPlayer(EPiece::pumpkin);
	//monopolishGame->AddPlayer(EPiece::dog);
	//monopolishGame->AddPlayer(EPiece::jaguar);

	return monopolishGame->Play();
}
