// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CMonopolish.h"
#include "CSquareFactory.h"
#include "CRandom.h"

using namespace std;
using namespace mp;

CMonopolish::CMonopolish() : CMonopolish(cout)
{
}

CMonopolish::CMonopolish(ostream& outputStream) : mOutStream(outputStream)
{
		// Setup
		mSquares = CSquareFactory::ReadFromFile(BOARD_SETUP_FILENAME);
}

void CMonopolish::Play()
{
	mOutStream << "Welcome to Monopol-ish" << endl << endl;

	if (mPlayers.empty())
	{
		mOutStream << "Add some players before starting the game" << endl;
		return;
	}

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
		player->DisplayBalance(mOutStream);

		float winnerBalance = mPlayers.at(winnerIndex)->GetBalance();
		if (player->GetBalance() > winnerBalance)
		{
			winnerIndex = i;
		}

		++i;
	}

	if (!mPlayers.empty())
	{
		mOutStream << *(mPlayers.at(winnerIndex)) << " wins" << endl;
	}
}

void CMonopolish::Round(int roundNo)
{
	mOutStream << "round " << roundNo << endl;

	for (const auto& player : mPlayers)
	{
		Turn(player);
	}

	mOutStream << endl;
}

void CMonopolish::Turn(const unique_ptr<CPlayer>& player)
{
	unsigned int diceRoll{unsigned(CRandom::Random())};
	mOutStream << *player << " rolls " << diceRoll << endl;
	mOutStream << *player << " lands on " << endl;

	player->DisplayBalance(mOutStream);
}

bool CMonopolish::AddPlayer(EPiece playingPiece)
{
	bool pieceTaken{mPieces.count(playingPiece) == 1};

	if (!pieceTaken)
	{
		mPieces.insert(playingPiece);
		mPlayers.push_back(make_unique<CPlayer>(playingPiece));
	}

	return pieceTaken;
}
