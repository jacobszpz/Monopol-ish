#include <vector>

#include "gtest/gtest.h"
#include "CTextFiles.h"

using namespace std;

TEST(CTextFilesTests, TestSplit)
{
	string testcase = "a b c";
	vector<string> expected{ "a", "b", "c" };
	ASSERT_EQ(jsan::CTextFiles::Split(testcase), expected);
}
