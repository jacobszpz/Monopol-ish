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

int CMonopolish::Play()
{
	mOutStream << "Welcome to Monopol-ish" << endl << endl;

	if (mPlayers.empty())
	{
		mOutStream << "Add some players before starting the game" << endl;
		return 1;
	}

	// Play
	for (unsigned int i = 1; i <= ROUNDS_NO; ++i)
	{
		Round(i);
	}

	mOutStream << "Game Over" << endl;
	DisplayPlayerBalances();

	return 0;
}

void CMonopolish::DisplayPlayerBalances()
{
	int i = 0;
	EPiece winnerPiece = EPiece::none;

	for (const auto& player : mPlayers)
	{
		player.second->DisplayBalance(mOutStream);

		float winnerBalance = mPlayers.at(winnerPiece)->GetBalance();
		if (player.second->GetBalance() > winnerBalance)
		{
			winnerPiece = player.first;
		}

		++i;
	}

	if (!mPlayers.empty())
	{
		mOutStream << *(mPlayers.at(winnerPiece)) << " wins" << endl;
	}
	mOutStream << mBank->GetBalance() << endl;
}

void CMonopolish::Round(int roundNo)
{
	mOutStream << "round " << roundNo << endl;

	for (const auto& player : mPlayers)
	{
		Turn(player.second);
	}

	mOutStream << endl;
}

void CMonopolish::Turn(const unique_ptr<IPlayer>& player)
{
	unsigned int diceRoll{unsigned(CRandom::Random())};
	unsigned int newPosition = (player->GetPosition() + diceRoll) % mBoard->GetNumberOfSquares();
	CSquare& landingSquare = mBoard->GetSquare(newPosition);
	player->SetPosition(newPosition);

	mOutStream << *player << " rolls " << diceRoll << endl;
	mOutStream << *player << " lands on " << landingSquare << endl;
	landingSquare.PlayerLands(*player, mPlayers, *mBank, mOutStream);
	player->DisplayBalance(mOutStream);
}

bool CMonopolish::AddPlayer(EPiece playingPiece)
{
	bool pieceTaken{mPlayers.count(playingPiece) == 1};

	if (!pieceTaken)
	{
		mPlayers.insert(pair<EPiece,unique_ptr<IPlayer>>(playingPiece,
			make_unique<CPlayer>(playingPiece, *mBoard)));
		mPlayers.at(playingPiece)->Receive(mBank->Withdraw(PLAYER_INITIAL_BONUS));
	}

	return pieceTaken;
}
