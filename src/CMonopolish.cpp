// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CMonopolish.h"
#include "CSquareFactory.h"

using namespace std;
using namespace mp;

CMonopolish::CMonopolish() : CMonopolish(cout)
{
}

CMonopolish::CMonopolish(ostream& outputStream) : mOutStream(outputStream)
{
		// Setup
		CSquareFactory::ReadFromFile(BOARD_SETUP_FILENAME);
}

void CMonopolish::Play()
{
	mOutStream << "Welcome to Monopol-ish" << endl;

	// Play
	for (unsigned int i = 1; i <= ROUNDS_NO; ++i)
	{
		Round(i);
	}

	mOutStream << "Game Over" << endl;

	DisplayPlayerBalances();
}

void CMonopolish::DisplayPlayerBalances()
{
	int i = 0;
	int winnerIndex = 0;

	for (const auto& player : mPlayers)
	{
		mOutStream << *player << " has £" << player->GetBalance() << endl;
		float winnerBalance = mPlayers.at(winnerIndex)->GetBalance();

		if (player->GetBalance() > winnerBalance)
		{
			winnerIndex = i;
		}

		++i;
	}

	mOutStream << *(mPlayers.at(winnerIndex)) << " wins" << endl;
}

void CMonopolish::Round(int roundNo)
{
	mOutStream << "round " << roundNo << endl;

	for (const auto& player : mPlayers)
	{
		mOutStream << *player << " rolls " << 2 << endl;
		mOutStream << *player << " lands on " << endl;
	}
}

void CMonopolish::AddPlayer(EPiece playingPiece)
{
	mPlayers.push_back(make_unique<CPlayer>());
}
