// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */
#ifdef _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

#include <memory>
#include "CMonopolish.h"

using namespace mp;

int main()
{
	{// Create game
		std::unique_ptr<CMonopolish> monopolishGame{std::make_unique<CMonopolish>()};

		// Add players
		monopolishGame->AddPlayer(EPiece::hamster);
		monopolishGame->AddPlayer(EPiece::pumpkin);
		monopolishGame->AddPlayer(EPiece::dog);
		monopolishGame->AddPlayer(EPiece::jaguar);

		// Play game
		monopolishGame->Play();
	}
	#ifdef _WIN32
		_CrtDumpMemoryLeaks();
		system("pause");
	#endif
}
