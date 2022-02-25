#include <iostream>
#include <string>
#include <sstream>

#include "gtest/gtest.h"
#include "EPiece.h"

using namespace std;
using namespace mp;

TEST(EPiece_Test, OutputStreamPumpkin)
{
	stringstream outputStream;
	outputStream << EPiece::pumpkin;
	string result = outputStream.str();
	string expected = "pumpkin";
	ASSERT_EQ(result, expected);
}

TEST(EPiece_Test, OutputStreamHamster)
{
	stringstream outputStream;
	outputStream << EPiece::hamster;
	string result = outputStream.str();
	string expected = "hamster";
	ASSERT_EQ(result, expected);
}
