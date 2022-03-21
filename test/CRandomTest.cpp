#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "CDie.h"

using namespace std;
using namespace mp;

TEST(CRandomTest, RandomBetween1And6)
{
	srand( static_cast<unsigned int> (time(0)) );
	const int min = 1;
	const int max = 6;

	int result = CDie::Throw();

	ASSERT_LE(result, max);
	ASSERT_GE(result, min);
}
