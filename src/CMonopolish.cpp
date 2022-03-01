// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CMonopolish.h"
#include "CSquareFactory.h"
#include "CRandom.h"
#include "CBank.h"

using namespace std;
using namespace mp;

CMonopolish::CMonopolish() : CMonopolish(cout)
{
}

CMonopolish::CMonopolish(ostream& outputStream) : mOutStream(outputStream)
{
		// Setup
		mBoard = make_unique<CBoard>(BOARD_SETUP_FILENAME);
		mBank = make_unique<CBank>(BANK_INITIAL_RESERVES);
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
	mOutStream << mBank->GetBalance() << endl;
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
	unsigned int newPosition = (player->GetPosition() + diceRoll) % mBoard->GetNumberOfSquares();
	CSquare& landingSquare = mBoard->GetSquare(newPosition);
	player->SetPosition(newPosition);

	mOutStream << *player << " rolls " << diceRoll << endl;
	mOutStream << *player << " lands on " << landingSquare << endl;
	landingSquare.PlayerLands(*player, mOutStream);
	player->DisplayBalance(mOutStream);
}

bool CMonopolish::AddPlayer(EPiece playingPiece)
{
	bool pieceTaken{mPieces.count(playingPiece) == 1};

	if (!pieceTaken)
	{
		mPieces.insert(playingPiece);
		mPlayers.push_back(make_unique<CPlayer>(playingPiece, *mBoard, *mBank));
		mPlayers.back()->ReceiveMoney(PLAYER_INITIAL_BONUS);
	}

	return pieceTaken;
}
