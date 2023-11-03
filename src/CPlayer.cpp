// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include <iostream>
#include "CPlayer.h"
#include "CBank.h"
#include "CBoard.h"
#include "COwnershipCard.h"
#include "CDie.h"

using namespace std;
using namespace mp;

CPlayer::CPlayer(EPiece playingPiece, unique_ptr<CBoard>& board) : mPiece(playingPiece), mBoard(board)
{
}

CPlayer::~CPlayer() {}

EPiece CPlayer::GetPiece() const
{
	return mPiece;
}

float CPlayer::GetBalance() const
{
	return mMoney;
}

void CPlayer::SetBalance(float newBalance)
{
	mMoney = newBalance;
}

void CPlayer::BalanceCheck(ostream& outputStream, unique_ptr<CBank>& bank)
{
	// Check if mortgaging or reedeming is possible
	for (auto& ownedSquare : mProperties)
	{
		if (ownedSquare->CanBeMortgaged())
		{
			if (ownedSquare->IsMortgaged() && mMoney >= ownedSquare->GetCost())
			{
				// Redeem
				outputStream << GetPiece() << " redeems " << ownedSquare->GetName();
				outputStream << " and pays " << POUND << ownedSquare->GetCost() << endl;
				bank->Deposit(Pay(ownedSquare->GetCost()));
				ownedSquare->SetMortgaged(false);
			}

			if (mMoney < 0 && !ownedSquare->IsMortgaged())
			{
				// Mortgage
				outputStream << GetPiece() << " mortgages " << ownedSquare->GetName();
				outputStream << " for " << POUND << ownedSquare->GetCost() << endl;
				Receive(bank->Withdraw(ownedSquare->GetCost()));
				ownedSquare->SetMortgaged(true);
			}
		}
	}

	if (mMoney < 0)
	{
		mBankrupt = true;
		outputStream << GetPiece() << " has become bankrupt." << endl;
	}
}

float CPlayer::Pay(float amount)
{
	mMoney -= amount;
	return amount;
}

void CPlayer::Receive(float amount)
{
	mMoney += amount;
}

void CPlayer::Own(IOwnableSquare& ownedSquare)
{
	mProperties.insert(make_unique<COwnershipCard>(ownedSquare, mProperties.size()));

	EColour squareColour = ownedSquare.GetColour();

	// Save count of number of properties with a certain color
	if (mPropertyColours.count(squareColour) == 0)
	{
		mPropertyColours[squareColour] = 0;
	}

	mPropertyColours.at(squareColour) += 1;


}

bool CPlayer::HasAllOfColour(EColour squareColour) {
	// Player owns all squares of this colour?
	auto totalCount = mBoard->GetCountByColour(squareColour);
	return mPropertyColours.at(squareColour) == totalCount;
}


bool CPlayer::IsBankrupt()
{
	return mBankrupt;
}

unsigned int CPlayer::GetPosition() const
{
	return mPosition;
}

void CPlayer::SetPosition(unsigned int position)
{
	mPosition = position;
}

void CPlayer::SetPosition(ESquareType square)
{
	if (square == ESquareType::Jail)
	{
		mPosition = mBoard->GetJailSquareIndex();
	}
}

void CPlayer::DisplayBalance(std::ostream& outputStream) const
{
	outputStream << GetPiece() << " has " << POUND << GetBalance() << endl;
}

unsigned int CPlayer::ThrowDie(std::ostream& outputStream) const
{
	unsigned int throwResult = unsigned(CDie::Throw());
	outputStream << GetPiece() << " rolls " << throwResult << endl;
	return throwResult;
}
//
// ostream& mp::operator << (ostream& outputStream, const CPlayer player)
// {
// 		outputStream << player.GetPiece();
// 		return outputStream;
// }
