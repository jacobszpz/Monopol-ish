// Jacob Sánchez Pérez

/** @file
 * @author Jacob Sánchez Pérez <jsanchez-perez@uclan.ac.uk>
 */

#include "CPlayer.h"
#include "CBank.h"
#include "CBoard.h"

using namespace std;
using namespace mp;

CPlayer::CPlayer(EPiece playingPiece, CBoard& board, CBank& bank) : mPiece(playingPiece), mBoard(board), mBank(bank)
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

void CPlayer::PayMoney(float amount)
{
	mMoney -= amount;
	// TODO: Should this happen?
	mBank.Deposit(amount);
}

void CPlayer::ReceiveMoney(float amount)
{
	mMoney += mBank.Withdraw(amount);
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
	outputStream << GetPiece() << " has £" << GetBalance() << endl;
}
//
// ostream& mp::operator << (ostream& outputStream, const CPlayer player)
// {
// 		outputStream << player.GetPiece();
// 		return outputStream;
// }
