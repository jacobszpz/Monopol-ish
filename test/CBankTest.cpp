#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "CBank.h"

using namespace std;
using namespace mp;

TEST(CBank_Deposit, HandleHundreds)
{
	float expected = 200;
	CBank bank = CBank();
	bank.Deposit(200);
	float result = bank.GetBalance();

	ASSERT_EQ(result, expected);
}

TEST(CBank_Withdraw, HandleLessThanReserves)
{
	float expected = 100;
	CBank bank = CBank(200);
	float result = bank.Withdraw(100);
	ASSERT_EQ(result, expected);
}

TEST(CBank_Withdraw, HandleLessThanReservesBalance)
{
	float expected = 50;
	CBank bank = CBank(200);

	bank.Withdraw(150);
	float result = bank.GetBalance();

	ASSERT_EQ(result, expected);
}

TEST(CBank_Withdraw, HandleSameAsReserves)
{
	float expected = 200;
	CBank bank = CBank(200);
	float result = bank.Withdraw(200);
	ASSERT_EQ(result, expected);
}

TEST(CBank_Withdraw, HandleSameAsReservesBalance)
{
	float expected = 0;
	CBank bank = CBank(200);

	bank.Withdraw(200);
	float result = bank.GetBalance();

	ASSERT_EQ(result, expected);
}

TEST(CBank_Withdraw, HandleMoreThanReserves)
{
	float expected = 0;
	CBank bank = CBank(200);
	float result = bank.Withdraw(201);
	ASSERT_EQ(result, expected);
}

TEST(CBank_Withdraw, HandleMoreThanReservesBalance)
{
	float expected = 200;
	CBank bank = CBank(200);

	bank.Withdraw(201);
	float result = bank.GetBalance();

	ASSERT_EQ(result, expected);
}

TEST(CBank_Withdraw, HandleMuchMoreThanReserves)
{
	float expected = 0;
	CBank bank = CBank(200);
	float result = bank.Withdraw(2000);
	ASSERT_EQ(result, expected);
}
