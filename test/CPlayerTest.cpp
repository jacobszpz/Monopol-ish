#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "CPlayer.h"
#include "EPiece.h"

using namespace std;
using namespace mp;

TEST(CPlayer_OutOverloadTest, HandlePumpkin)
{
	string expected = "Pumpkin";
	stringstream outputStream;

	auto player = CPlayer(EPiece::pumpkin);
	outputStream << player;
	string result = outputStream.str();

	ASSERT_EQ(result, expected);
}

TEST(CPlayer_GetBalanceTest, InitialBalance)
{
	float expected = 1500;
	auto player = CPlayer(EPiece::pumpkin);
	float result = player.GetBalance();

	ASSERT_EQ(result, expected);
}

TEST(CPlayer_GetPieceTest, HandlePumpkin)
{
	EPiece expected = EPiece::pumpkin;
	auto player = CPlayer(EPiece::pumpkin);
	EPiece result = player.GetPiece();

	ASSERT_EQ(result, expected);
}
