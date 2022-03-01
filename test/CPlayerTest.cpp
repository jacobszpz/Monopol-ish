#include <iostream>
#include <string>

#include "gtest/gtest.h"

#include "CPlayer.h"
#include "CBoard.h"
#include "EPiece.h"

using namespace std;
using namespace mp;

TEST(CPlayer_OutOverloadTest, Pumpkin)
{
	string expected = "Pumpkin";
	stringstream outputStream;
	CBank bank = CBank();
	CBoard board = CBoard();

	auto player = CPlayer(EPiece::pumpkin, board, bank);
	outputStream << player;
	string result = outputStream.str();

	ASSERT_EQ(result, expected);
}

TEST(CPlayer_GetBalanceTest, InitialBalance)
{
	float expected = 0;
	CBank bank = CBank();
	CBoard board = CBoard();
	auto player = CPlayer(EPiece::pumpkin, board, bank);
	float result = player.GetBalance();

	ASSERT_EQ(result, expected);
}

TEST(CPlayer_GetPieceTest, Pumpkin)
{
	EPiece expected = EPiece::pumpkin;
	CBank bank = CBank();
	CBoard board = CBoard();
	auto player = CPlayer(EPiece::pumpkin, board, bank);
	EPiece result = player.GetPiece();

	ASSERT_EQ(result, expected);
}
