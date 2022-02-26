#include <iostream>
#include <string>
#include <sstream>

#include "gtest/gtest.h"
#include "EPiece.h"

using namespace std;
using namespace mp;

TEST(EPieceTest, OutputStreamPumpkin)
{
	stringstream outputStream;
	outputStream << EPiece::pumpkin;
	string result = outputStream.str();
	string expected = "Pumpkin";
	ASSERT_EQ(result, expected);
}

TEST(EPieceTest, OutputStreamHamster)
{
	stringstream outputStream;
	outputStream << EPiece::hamster;
	string result = outputStream.str();
	string expected = "Hamster";
	ASSERT_EQ(result, expected);
}
