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

CPlayer::CPlayer(EPiece playingPiece, CBoard& board) : mPiece(playingPiece), mBoard(board)
{
}

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

void CPlayer::BalanceCheck(ostream& outputStream, CBank bank)
{
	// Check if mortgaging or reedeming is possible
	for (auto& ownedSquare : mProperties)
	{
		if (ownedSquare.IsMortgaged() && mMoney >= ownedSquare.GetCost())
		{
			// Redeem
			outputStream << *this << " redeems " << ownedSquare.GetName();
			outputStream << " and pays " << POUND << ownedSquare.GetCost() << endl;
			bank.Deposit(Pay(ownedSquare.GetCost()));
			ownedSquare.SetMortgaged(false);
		}

		if (mMoney < 0 && !ownedSquare.IsMortgaged())
		{
			// Mortgage
			outputStream << *this << " mortgages " << ownedSquare.GetName();
			outputStream << " for " << POUND << ownedSquare.GetCost() << endl;
			Receive(bank.Withdraw(ownedSquare.GetCost()));
			ownedSquare.SetMortgaged(true);
		}
	}

	if (mMoney < 0)
	{
		mBankrupt = true;
		outputStream << *this << " has become bankrupt." << endl;
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
	mProperties.insert(COwnershipCard(ownedSquare, mProperties.size()));
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
		mPosition = mBoard.GetJailSquareIndex();
	}
}

void CPlayer::DisplayBalance(std::ostream& outputStream) const
{
	outputStream << GetPiece() << " has " << POUND << GetBalance() << endl;
}

unsigned int CPlayer::ThrowDie(std::ostream& outputStream) const
{
	unsigned int throwResult = unsigned(CDie::Throw());
	outputStream << *this << " rolls " << throwResult << endl;
	return throwResult;
}
//
// ostream& mp::operator << (ostream& outputStream, const CPlayer player)
// {
// 		outputStream << player.GetPiece();
// 		return outputStream;
// }
