#include <vector>

#include "gtest/gtest.h"
#include "CTextFiles.h"

using namespace std;

TEST(CTextFiles_SplitTest, HandleAlphabet)
{
	string testcase = "a b c d e f g";
	vector<string> expected{ "a", "b", "c", "d", "e", "f", "g" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase), expected);
}

TEST(CTextFiles_SplitTest, HandleSingleElement)
{
	string testcase = "a";
	vector<string> expected{ "a" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase), expected);
}

TEST(CTextFiles_SplitTest, HandleCharOnEnds)
{
	string testcase = ":a:b:c:";
	vector<string> expected{ "", "a", "b", "c", "" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase, ':'), expected);
}

TEST(CTextFiles_SplitTest, HandleColon)
{
	string testcase = "a:b:c:d:e:f:g";
	vector<string> expected{ "a", "b", "c", "d", "e", "f", "g" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase, ':'), expected);
}

TEST(CTextFiles_SplitTest, HandleComma)
{
	string testcase = "a,b,c,d,e,f,g";
	vector<string> expected{ "a", "b", "c", "d", "e", "f", "g" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase, ','), expected);
}

TEST(CTextFiles_SplitTest, HandleLetter)
{
	string testcase = "suspiciously";
	vector<string> expected{ "", "u", "piciou", "ly" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase, 's'), expected);
}

TEST(CTextFiles_SplitTest, HandleMonopolishLine)
{
	string testcase = "1 Corporation Street 300 45 6";
	vector<string> expected{"1", "Corporation", "Street", "300", "45", "6" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase), expected);
}

TEST(CTextFiles_SplitTest, HandleReturnCarriageLine)
{
	string testcase = "1 Corporation Street 300 45 6\r";
	vector<string> expected{"1", "Corporation", "Street", "300", "45", "6" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase), expected);
}

TEST(CTextFiles_StripTest, HandleSingleSpace)
{
	string testcase = " a b c d ";
	string expected = "a b c d";
	ASSERT_EQ(jsan::CTextFiles::Strip(testcase), expected);
}

TEST(CTextFiles_StripTest, HandleMultipleSpace)
{
	string testcase = "   a b c d   ";
	string expected = "a b c d";
	ASSERT_EQ(jsan::CTextFiles::Strip(testcase), expected);
}

TEST(CTextFiles_StripTest, HandleReturn)
{
	string testcase = "\ra b c d\r";
	string expected = "a b c d";
	ASSERT_EQ(jsan::CTextFiles::Strip(testcase), expected);
}

TEST(CTextFiles_StripTest, HandleTabs)
{
	string testcase = "\t\t\ta b c d\t\t\t";
	string expected = "a b c d";
	ASSERT_EQ(jsan::CTextFiles::Strip(testcase), expected);
}

TEST(CTextFiles_StripTest, HandleNewlines)
{
	string testcase = "\n\na b c d\n\n";
	string expected = "a b c d";
	ASSERT_EQ(jsan::CTextFiles::Strip(testcase), expected);
}
