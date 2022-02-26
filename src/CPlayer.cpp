// Jacob Sánchez Pérez

#include "CPlayer.h"

using namespace std;
using namespace mp;

CPlayer::CPlayer(EPiece playingPiece) : mPiece(playingPiece)
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

void CPlayer::DisplayBalance(std::ostream& outputStream) const
{
	outputStream << GetPiece() << " has £" << GetBalance() << endl;
}

ostream& mp::operator << (ostream& outputStream, const CPlayer player)
{
		outputStream << player.GetPiece();
		return outputStream;
}
