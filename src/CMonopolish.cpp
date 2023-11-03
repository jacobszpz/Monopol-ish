// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CMonopolish.h"
#include "CSquareFactory.h"
#include "CBank.h"
#include "CDie.h"
#include "CTextFiles.h"

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
		// Seed from file
		auto seedLines = jsan::CTextFiles::GetLinesFromFile(DIE_SEED_FILENAME);
		CDie::Seed(stoi(seedLines.front()));
}

int CMonopolish::Play()
{
	mOutStream << "Welcome to Monopol-ish" << endl << endl;

	if (mPlayers.empty())
	{
		mOutStream << "Add some players before starting the game" << endl;
		return 1;
	}

	bool playersLeft = true;
	// Play
	for (unsigned int i = 1; i <= ROUNDS_NO && playersLeft; ++i)
	{
		playersLeft = Round(i);
	}

	mOutStream << "Game Over" << endl;
	mOutStream << "=========" << endl;
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

		if (winnerPiece != EPiece::none)
		{
			float winnerBalance = mPlayers.at(winnerPiece)->GetBalance();

			if (player.second->GetBalance() > winnerBalance)
			{
				winnerPiece = player.first;
			}
		}
		else
		{
			winnerPiece = player.first;
		}

		++i;
	}

	// Declare winner
	if (!mPlayers.empty())
	{
		mOutStream << mPlayers.at(winnerPiece)->GetPiece() << " wins!" << endl;
	}
}

bool CMonopolish::Round(int roundNo)
{
	mOutStream << "round " << roundNo << endl;
	mOutStream << "========" << endl;
	unsigned int nBankrupt = 0;
	for (auto& player : mPlayers)
	{
		if (!player.second->IsBankrupt())
		{
			Turn(player.second);
			mOutStream << endl;
		} else {
			++nBankrupt;
		}

		if (nBankrupt == mPlayers.size() - 1)
		{
			return false;
		}
	}

	return true;
}

void CMonopolish::Turn(unique_ptr<IPlayer>& player)
{
	auto dieRoll{player->ThrowDie(mOutStream)};
	auto currentPosition = player->GetPosition();
	auto newPosition = (currentPosition + dieRoll) % mBoard->GetNumberOfSquares();

	if (newPosition < currentPosition)
	{
		// Player passed GO!
		auto goSquareIndex = mBoard->GetGoSquareIndex();
		mBoard->GetSquare(goSquareIndex)->PlayerPasses(player, mPlayers, mBank, mOutStream);
	}

	unique_ptr<CSquare>& landingSquare = mBoard->GetSquare(newPosition);
	player->SetPosition(newPosition);

	mOutStream << player->GetPiece() << " lands on " << landingSquare->GetName() << endl;
	landingSquare->PlayerLands(player, mPlayers, mBank, mOutStream);
	player->BalanceCheck(mOutStream, mBank);
	player->DisplayBalance(mOutStream);
}

bool CMonopolish::AddPlayer(EPiece playingPiece)
{
	bool pieceTaken{mPlayers.count(playingPiece) == 1};

	if (!pieceTaken)
	{
		// Add player
		mPlayers.insert({playingPiece,
			make_unique<CPlayer>(playingPiece, mBoard)});
		// Initial player bonus
		mPlayers.at(playingPiece)->Receive(mBank->Withdraw(PLAYER_INITIAL_BONUS));
	}

	return pieceTaken;
}
